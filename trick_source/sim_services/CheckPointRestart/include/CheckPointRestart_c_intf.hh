/* 
    PURPOSE: 
        (Memory Manager Wrapper C interface) 
*/

/* 
 * $Id: CheckPointRestart_c_intf.hh 3417 2014-02-07 15:55:32Z alin $
 */

/**
 * @file
 */

#ifndef _CHECKPOINTRESTARTCINTF_HH_
#define _CHECKPOINTRESTARTCINTF_HH_

#ifdef __cplusplus
extern "C" {
#endif

/* set pre_init_checkpoint flag */
int checkpoint_pre_init(int yes_no) ;

/* set post_init_checkpoint flag */
int checkpoint_post_init(int yes_no) ;

/* set end_checkpoint flag */
int checkpoint_end(int yes_no) ;

/* set pre_init_checkpoint flag */
int get_checkpoint_pre_init() ;

/* set post_init_checkpoint flag */
int get_checkpoint_post_init() ;

/* set end_checkpoint flag */
int get_checkpoint_end() ;

/* set safestore_enabled flag */
int checkpoint_safestore_set_enabled(int yes_no) ;

/* set the cpu to use for checkpoints */
int checkpoint_cpu( int in_cpu_num ) ;

/* safestore checkpoint call accessible from C code */
int checkpoint_safestore( double in_period ) ;

/* get checkpoint dump file name */
const char * checkpoint_get_output_file() ;

/* get checkpoint load file name */
const char * checkpoint_get_load_file() ;

/* checkpoint call accessible from C code */
int checkpoint( const char * file_name );

/* set dmtcp safestore_enabled flag */
int dmtcp_checkpoint_safestore_set_enabled(int yes_no) ;

/* dmtcp safestore checkpoint call accessible from C code */
int dmtcp_checkpoint_safestore( double in_period ) ;

/* dmtcp checkpoint call accessible from C code */
int dmtcp_checkpoint( const char * file_name );

/* checkpoint for specific sim objects call from C code */
int checkpoint_objects( const char * file_name, const char * objects ) ;

/* load_checkpoint call accessible from C code */
int load_checkpoint( const char * file_name ) ;
int load_checkpoint_job() ;

void * get_address( const char * var_name ) ;

#ifdef __cplusplus
}

#include <string>
int next_attr_name( std::string & name ) ;

#endif

#endif
