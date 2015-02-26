/*
PURPOSE:
    ( The job class that the executive schedules and runs )

PROGRAMMERS:
    ((Alex Lin) (NASA) (May 2009) (OO))
*/

/*
 * $Id: JobData.hh 411 2009-11-17 21:34:25Z lin $
 */

#ifndef _SCHEDULEDQUEUEINSTRUMENT_HH_
#define _SCHEDULEDQUEUEINSTRUMENT_HH_

#include <string>

#include "sim_services/SimObject/include/InstrumentBase.hh"
#include "sim_services/SimObject/include/JobData.hh"

namespace Trick {

    /**
     * This class is the ScheduledJobQueueInstrument class.  This class contains extra job data that
     * points to the instrumentation's target job as well as event data used by some types of
     * instrumentation jobs.
     *
     * @author Dan A. Strauss
     * @author Alexander S. Lin
     *
     * @date Jan. 2010
     *
     */
    class ScheduledJobQueueInstrument : public Trick::InstrumentBase {

        public:

            /** The instrumentation job itself\n */
            Trick::JobData * instru_job ;          /**<  trick_io(**) */

            /** The target job of the instrumentation (instrument is inserted before or after target).\n */
            Trick::JobData * target_job ;          /**<  trick_io(**) */

            /**
             * Constructor\n
             * @param inst_job - instrumentation base job as listed in S_define file
             * @param targ_job - target job that is to be instrumented
             */
            ScheduledJobQueueInstrument( Trick::JobData* inst_job, Trick::JobData* targ_job);

            ~ScheduledJobQueueInstrument();

            /**
             * Calls the instumentation jobs only
             * @return always 0
             */
            virtual int call() ;
    } ;

} ;

#endif

