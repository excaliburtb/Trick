/*
 * $Id: DPC_std_curve.cpp 1896 2011-08-29 19:31:08Z dpanter $
 */

#include "DPC/DPC_std_curve.hh"
#include "math.h"
#include "../../units/include/Unit.hh"

// CONSTRUCTOR
DPC_std_curve::DPC_std_curve(
                             DPM_curve*               Curve_spec, 
                             DPM_run*                 Run,
                             DPC_datastream_supplier *ds_supplier,
                             DPM_time_constraints    *Time_constraints ) throw (std::logic_error)
    : DPC_curve() {

    char work[255];
    char *temp_s;

    unsigned int case_index = 0;
    unsigned int success = 0;
    const char*  run_dir = Run->getDir();
    unsigned int number_of_cases = Curve_spec->NumberOfVarCases();

    x_actual_units = NULL;  
    y_actual_units = NULL;  

    data_src_label = NULL;
    time_conversion = NULL;

    // While we haven't found found a variable-pair that works for
    // this RUN and we haven't exhausted all of the variable-pairs.

    while ( !success && (case_index < number_of_cases)) {

        x_var = Curve_spec->getXVar(case_index);
        const char* x_var_name = x_var->getName();
        const char* x_var_units = x_var->AttributeValue("units");
        const char* x_var_from_units = x_var->AttributeValue("from_units");

        y_var = Curve_spec->getYVar(case_index);
        const char* y_var_name = y_var->getName();
        const char* y_var_units = y_var->AttributeValue("units");
        const char* y_var_from_units = y_var->AttributeValue("from_units");

        // If the X-axis represents time then this curve is of type:
        //
        //                      <X,Y> = <t,A(t)>

        if ( strcmp( (const char *)x_var_name, Run->getTimeName()) == 0) {

            // Because the X-axis is time, we handle it's unit conversion
            // here. Note that for the Y-axis or where the X-axis is not time,
            // unit conversion handled by the corresponding
            // DPC_UnitConvDataStream. 
    
            // If the user has specified a conversion to units other than seconds,
            // then generate a units conversion from seconds to those units.
            if ((x_var_units != NULL) && (strcmp( x_var_units,"s" ) != 0)) {
      
                Unit *to_unit;
                Unit *from_unit;
    
                // Create the "to_unit" object.
                try {
                    to_unit = new Unit(x_var_units);
                } catch (Unit::CONVERSION_ERROR) {
                    delete to_unit;
                    to_unit = NULL;

                    std::cerr << "ERROR: For the curve <X,Y> = <" << x_var_name << ", "
                              << y_var_name << ">, " << "the units (\""<< x_var_units
                              << "\") specified for " << x_var_name << " are invalid."
                              << std::endl;
                }

                // Create the "from_unit" object.
                // Note that in the case of time, from_units must be seconds.
                from_unit = new Unit("s");

                // If both the to_unit and from_unit objects are created
                // successfully then attempt to create the conversion.
                if (to_unit && from_unit) {

                    try {
                        time_conversion = from_unit->Conversion_to(to_unit);
                        x_actual_units = strdup( x_var_units);
                    } catch (Unit::CONVERSION_ERROR) {

                        std::cerr << "ERROR: For the curve <X,Y> = <" << x_var_name << ", "
                                  << y_var_name << ">, " << "seconds (\"s\") cannot be converted to (\""<< x_var_units
                                  << "\"), which have been specified for " << x_var_name << "."
                                  << std::endl;

                        time_conversion = new UCFn( "s","s", 1.0, 0.0);
                        x_actual_units = strdup("s");
                    }

                } else {
                    time_conversion = new UCFn( "s", "s", 1.0, 0.0);
                    x_actual_units = strdup("s");
                }

            } else {
                time_conversion = new UCFn( "s", "s", 1.0, 0.0);
                x_actual_units = strdup("s");
            } 

            // Create the one DataStream [A(t)] that we need for this curve.
            
            ds[0] = ds_supplier->getDataStream( y_var_name,
                                                y_var_units,
                                                y_var_from_units,
                                                Run,
                                                Time_constraints );
            if (ds[0] != NULL) {

                const char* ds_units = ds[0]->getUnit().c_str();

                y_actual_units = strdup(ds_units);

                // Tell our DataStream to start at the beginning.
                ds[0]->begin();

                // Since we are not going to use two DataStreams in this case set
                // the second one to NULL.
                ds[1] = NULL;

                // We've successfully initialized our curve from the variable-pair.
                success = 1;

            } else {        
                std::cerr << "ERROR: Variable \"" << y_var_name << "\" was\'nt found in " << std::endl
                          << "Run Directory \"" << run_dir << "\"" << std::endl; 
                std::cerr.flush();
            }

        } else {

            // The X-axis does not represent time so this curve is of type:
            //
            //                        <X,Y> = <A(t),B(t)>

            // Create the X-axis DataStream that we need for this curve.
            ds[0] = ds_supplier->getDataStream( x_var_name, x_var_units, x_var_from_units, Run, Time_constraints );

            // If we're successful then ...
            if (ds[0] != NULL) {

                x_actual_units = strdup( ds[0]->getUnit().c_str() );
                ds[0]->begin();

                // Create the Y-axis DataStream.
                ds[1] = ds_supplier->getDataStream( y_var_name, y_var_units, y_var_from_units, Run, Time_constraints );

                // If we're successful then ...
                if (ds[1] != NULL) {
                    y_actual_units = strdup( ds[1]->getUnit().c_str() );
                    ds[1]->begin();

                    // We're succesfully initialized our curve from the variable-pair.
                    success = 1;

                } else {
                    delete ds[0]; ds[0] = NULL;
                    std::cerr << "Variable \"" << y_var_name << "\" was\'nt found in " << std::endl
                              << "Run Directory \"" << run_dir << "\"" << std::endl; 
                    std::cerr.flush();
                }
            } else {
                std::cerr << "Variable \"" << x_var_name << "\" was\'nt found in " << std::endl
                          << "Run Directory \"" << run_dir << "\"" << std::endl; 
                std::cerr.flush();
            }
        }
        case_index++;
    }

    if (!success) {
        throw (std::logic_error("Failed to create curve."));
    }

    // ----------------------
    // Save the RUN directory.
    // ----------------------
    work[0] ='\0';
    if ((temp_s = strrchr((char*)run_dir,'/')) != NULL) {
        strcpy(work, temp_s+1);
    } else {
        strcpy(work, run_dir);
    }
    data_src_label = strdup(work);

}

// DESTRUCTOR
DPC_std_curve::~DPC_std_curve() {

    // We ONLY delete what we create.
    if ( ds[0] ) { 
        delete ds[0];
        ds[0] = NULL;
    };
    if ( ds[1] ) {
        delete ds[1];
        ds[1] = NULL; };

    if ( x_actual_units ) {
        free( x_actual_units);
        x_actual_units = NULL;
    }
    if ( y_actual_units ) {
        free( y_actual_units);
        y_actual_units = NULL;
    }

    if ( data_src_label ) {
        free( data_src_label);
        data_src_label = NULL;
    }
    if ( time_conversion ) {
        delete time_conversion;
        time_conversion = NULL;
    }
}

// MEMBER FUNCTION
const char* DPC_std_curve::getXUnits() {
    return ( x_actual_units);
}

// MEMBER FUNCTION
const char* DPC_std_curve::getYUnits() {
    return ( y_actual_units);
}

// MEMBER FUNCTION
const char *DPC_std_curve::getDataSrcLbl() {
    return( data_src_label);
}

// MEMBER FUNCTION
int DPC_std_curve::getXY(double *X_value, double *Y_value) {

    double t1,t2,v1,v2;
    int eos;

    if (ds[0]) {
        if (ds[1]) {
            eos = !(ds[0]->get( &t1, &v1) && ds[1]->get( &t2, &v2));
            while (!eos && ( fabs( t1 - t2) > T_TOLERANCE )) {
                if (t1 < t2) {
                    eos = ! ds[0]->get( &t1, &v1);
                } else {
                    eos = ! ds[1]->get( &t2, &v2);
                }
            }
            if (!eos) { 
                *X_value = v1;
                *Y_value = v2;
                return(1);
            }
        } else {     
            eos = !ds[0]->get( &t1, &v1);
            if (!eos) {
                *X_value = time_conversion->eval( t1);
                *Y_value = v1;
                return(1);
	    }
	}
    }
    return(0);
}

// MEMBER FUNCTION
void DPC_std_curve::begin() {
    if (ds[0]) ds[0]->begin();
    if (ds[1]) ds[1]->begin();
}

