/*
    PURPOSE:
        (DMTCP)
*/

/*
 * $Id: DMTCP.hh 2566 2012-09-06 22:01:28Z mbhatta $
 */

/**
 * @file DMTCP.hh
 */

#ifndef _DMTCP_HH_
#define _DMTCP_HH_

#ifdef _DMTCP
#include "dmtcpaware.h"
#endif

#include <queue>

#include "sim_services/DMTCP/include/dmtcp_checkpoint_c_intf.hh"
#include "sim_services/Scheduler/include/Scheduler.hh"

namespace Trick {
    class DMTCP : public Trick::Scheduler {

        public:

            DMTCP() ;

            int init() ;
            int freeze() ;
            int pre() ;
            int post() ;
            int restart() ;
            int call_dmtcp();

            void dmtcpSetCheckpointNow() ;
            void dmtcpJobQueue( std::string file_name );
            void renameRestartScript();
            void dmtcpSystemCmd( const std::string& str );
            void dmtcpCleanup();
            void dmtcpSafestoreDir();
            void dmtcpRenameCmd();            

            bool isSpecialCharacter( const std::string& str );

            std::string getScriptName();
            std::string splitFilename( const std::string& str );

            unsigned int dmtcp_ckpt_complete;
            std::priority_queue<std::string> dmtcp_checkpoint_jobs_queue ;

            virtual int write_s_job_execution( FILE * fp ) ;
            virtual int instrument_job_before(Trick::JobData * instrument_job) ;
            virtual int instrument_job_after(Trick::JobData * instrument_job) ;
            virtual int instrument_job_remove(std::string in_job) ;

        private:

            bool checkpoint_now ;
            char prev_checkpoint_dirname[1024] ;

            /** queue to hold jobs to be called before a checkpoint is dumped. */
            Trick::ScheduledJobQueue pre_queue ;              /* ** */

            /** queue to hold jobs to be called after a checkpoint is dumped. */
            Trick::ScheduledJobQueue post_queue ;         /* ** */

            /** queue to hold jobs to be called after a checkpoint is reloaded. */
            Trick::ScheduledJobQueue restart_queue ;              /* ** */
    } ;
}
#endif
