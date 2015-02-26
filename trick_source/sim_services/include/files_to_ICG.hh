#ifndef _FILES_TO_ICG_HH_
#define _FILES_TO_ICG_HH_

#include "trick_utils/math/include/reference_frame.h"
#include "sim_services/Clock/include/GetTimeOfDayClock.hh"
#include "sim_services/Clock/include/BC635Clock.hh"
#include "sim_services/Clock/include/TPROCTEClock.hh"
#include "sim_services/CommandLineArguments/include/CommandLineArguments.hh"
#include "sim_services/DMTCP/include/DMTCP.hh"
#include "sim_services/Executive/include/Executive.hh"
#include "sim_services/Environment/include/Environment.hh"
#include "sim_services/EventManager/include/Event.hh"
#include "sim_services/EventManager/include/EventProcessor.hh"
#include "sim_services/EventManager/include/EventManager.hh"
#include "sim_services/InputProcessor/include/IPPython.hh"
#include "sim_services/InputProcessor/include/IPPythonEvent.hh"
#include "sim_services/InputProcessor/include/MTV.hh"
#include "sim_services/JITInputFile/include/JITInputFile.hh"
#include "sim_services/JSONVariableServer/include/JSONVariableServer.hh"
#include "sim_services/JSONVariableServer/include/JSONVariableServerThread.hh"
#include "sim_services/MasterSlave/include/Master.hh"
#include "sim_services/MasterSlave/include/Slave.hh"
#include "sim_services/MasterSlave/include/MSSocket.hh"
#include "sim_services/MasterSlave/include/MSSharedMem.hh"
#include "sim_services/MemoryManager/include/MemoryManager.hh"
#include "sim_services/Message/include/MessageCout.hh"
#include "sim_services/Message/include/MessageFile.hh"
#include "sim_services/Message/include/MessageLCout.hh"
#include "sim_services/Message/include/MessagePublisher.hh"
#include "sim_services/Message/include/MessageTCDevice.hh"
#include "sim_services/Message/include/PlaybackFile.hh"
#include "sim_services/MonteCarlo/include/MonteCarlo.hh"
#include "sim_services/RealtimeSync/include/RealtimeSync.hh"
#include "sim_services/Timer/include/ITimer.hh"
#include "sim_services/VariableServer/include/VariableServer.hh"
#include "sim_services/Integrator/include/regula_falsi.h"
#include "sim_services/Integrator/include/Integrator.hh"
#include "sim_services/Integrator/include/IntegAlgorithms.hh"
#include "sim_services/Integrator/include/IntegLoopScheduler.hh"
#include "sim_services/Integrator/include/IntegLoopManager.hh"
#include "sim_services/Integrator/include/IntegLoopSimObject.hh"

#ifdef USE_ER7_UTILS_INTEGRATORS
#  include "sim_services/Integrator/er7_algorithms/ABM_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/Euler_Cromer_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/Euler_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/MM4_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/NL2_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/RK2_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/RK4_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/RKF45_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/RKF78_Integrator.hh"
#  include "sim_services/Integrator/er7_algorithms/RKG4_Integrator.hh"
/* from the er7_utils directory */
#  include "er7_utils/trick/include/files_to_ICG.hh"
#else
#  include "sim_services/Integrator/trick_algorithms/ABM_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/Euler_Cromer_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/Euler_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/MM4_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/NL2_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/RK2_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/RK4_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/RKF45_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/RKF78_Integrator.hh"
#  include "sim_services/Integrator/trick_algorithms/RKG4_Integrator.hh"
#endif

#include "sim_services/DataRecord/include/DataRecordDispatcher.hh"
#include "sim_services/DataRecord/include/DRAscii.hh"
#include "sim_services/DataRecord/include/DRBinary.hh"
#include "sim_services/DataRecord/include/DRHDF5.hh"
#include "sim_services/DebugPause/include/DebugPause.hh"
#include "sim_services/EchoJobs/include/EchoJobs.hh"
#include "sim_services/FrameLog/include/FrameLog.hh"
#include "sim_services/UnitTest/include/UnitTest.hh"
#include "sim_services/CheckPointRestart/include/CheckPointRestart.hh"
#include "sim_services/Sie/include/Sie.hh"
#include "sim_services/STL/include/STLInterface.hh"
#include "sim_services/ExternalApplications/include/SimControlPanel.hh"
#include "sim_services/ExternalApplications/include/TrickView.hh"
#include "sim_services/ExternalApplications/include/MalfunctionsTrickView.hh"
#include "sim_services/ExternalApplications/include/MonteMonitor.hh"
#include "sim_services/ExternalApplications/include/StripChart.hh"
#include "sim_services/RealtimeInjector/include/RtiStager.hh"
#include "sim_services/RealtimeInjector/include/RtiExec.hh"
#include "sim_services/Units/include/UnitsMap.hh"
#include "sim_services/Zeroconf/include/Zeroconf.hh"
#include "sim_services/include/Flag.h"
#include "trick_utils/math/include/wave_form.h"
#include "trick_utils/math/include/rand_generator.h"

#endif
