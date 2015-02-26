/*
PURPOSE:
    ( The base SimObject class that all simobjects and capabilites of Trick derive from )

PROGRAMMERS:
    ((Alex Lin) (NASA) (May 2009) (OO))
*/

/*
 * $Id: SimObject.hh 3383 2014-01-22 23:18:15Z alin $
 */
#ifndef _SIMOBJECT_HH_
#define _SIMOBJECT_HH_

#include <string>
#include <vector>

#include "sim_services/SimObject/include/JobData.hh"

namespace Trick {

    /**
     * This class is the base class for all SimObjects in the simulation.  It contains a the list of
     * jobs instantiated within the SimObject and the call functions to actually call the functions.
     * Typcally children classes are defined in the S_define file and the call_function routines are
     * auto generated by CP.
     *  
     * @author Alexander S. Lin
     *
     * @date Jan. 2010
     *
     */

    class SimObject {

        public:

            /** Name of SimObject given to object */
            std::string  name ;                                /* trick_units(--) */

            /** SimObject id assigned by CP */
            int  id ;                                     /* trick_units(--) */

            /** Included simobjects -- currently not used */
            std::vector <SimObject *> pre_component_objects ;  /* trick_io(**) */

            /** Included simobjects -- currently not used */
            std::vector <SimObject *> post_component_objects ; /* trick_io(**) */

            /**  Jobs in this sim_object */
            std::vector <Trick::JobData *> jobs ;              /* trick_io(**) */

            /**  Returns a job with a specific name. */
            Trick::JobData * get_job( std::string job_name , unsigned int instance_num = 1 ) ;

            /**  Add a job tag to all jobs in this sim_object */
            int add_tag( std::string ) ;

            /**  Add a job tag to particular job in this sim_object */
            int add_tag_to_job( std::string job_tag , std::string job_name ) ;

            /**
             * Includes a lower level SimObject where the lower level jobs are called before this SimObject
             * @param in_object - object to include
             * @param name - name of lower level SimObject
             * @return always 0
             */
            int add_pre_component_object(SimObject *, std::string name) ;

            /**
             * Includes a lower level SimObject where the lower level jobs are called after this SimObject
             * @param in_object - object to include
             * @param name - name of lower level SimObject
             * @return always 0
             */
            int add_post_component_object(SimObject *, std::string name) ;

            /**
             * Adds a job to the sim_object.  This call is typically in the S_source.cpp file
             * @param in_thread - thread number specified in S_define
             * @param in_id - job id given to job by CP
             * @param in_job_class_name - job name specified in S_define
             * @param sup_class_data - supplemental data to attach to job
             * @param in_cycle - job cycle specified in S_define
             * @param in_name - name of job specified in S_define
             * @param in_tag - group tag name specified in S_define
             * @param in_phase - job phase specified in S_define
             * @param in_start - job start time specified in S_define
             * @param in_stop - job stop time specified in S_define
             * @return the job added to the queue
             */
            Trick::JobData * add_job(int in_thread, int in_id, const char * in_job_class_name , void* sup_class_data ,
                        double in_cycle, const char * in_name, const char * in_tag = "", int in_phase = 60000 ,
                        double in_start = 0.0 , double in_stop = 1.0e37) ;

            /** Default destructor that doesn't do anything. */
            virtual ~SimObject() ;

            /**
             * Calls all jobs that are not "dynamic_event" class
             * @param curr_job - the current job instance
             * @return always 0
             */
            virtual int call_function( Trick::JobData * curr_job ) = 0 ;

            /**
             * Calls all jobs that are "dynamic_event" class
             * @param curr_job - the current job instance
             * @return always 0
             */
            virtual double call_function_double( Trick::JobData * curr_job ) = 0 ;

    } ;

} ;

#endif

