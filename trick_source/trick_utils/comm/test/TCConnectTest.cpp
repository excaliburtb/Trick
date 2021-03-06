/*
 * $Id: TCConnectTest.cpp 3368 2013-12-19 22:34:06Z jpenn1 $
 */

#include <gtest/gtest.h>

#include "trick_utils/comm/include/tc.h"
#include "trick_utils/comm/include/tc_proto.h"
#include "trick_utils/comm/include/attributes.h"
#include "trick_utils/comm/include/hs_msg.h"
#include "trick_utils/comm/include/trick_byteswap.h"
#include "trick_utils/comm/include/trick_error_hndlr.h"

class TCConnectTest : public testing::Test {

   protected:
      TCConnectTest(){}
      ~TCConnectTest(){}

      TCDevice* device;

      void SetUp(){

         /* device */
         device = (TCDevice *) malloc(sizeof(TCDevice));
         memset( (void *)device,'\0',sizeof(TCDevice) );
         device->hostname = "127.0.0.1";
         device->disabled = TC_COMM_FALSE;
         device->disable_handshaking = TC_COMM_DISABLED;
         strcpy(device->client_tag, "<empty>");

      }

      void TearDown(){
   
         free(device);
      }
};


TEST_F( TCConnectTest, testNoDevice ) {

   int connect_status = tc_connect( NULL );

   EXPECT_EQ( connect_status, -1 );
}

TEST_F( TCConnectTest, testDisabledDevice ) {

   device->disabled = TC_COMM_TRUE;

   int connect_status = tc_connect( device );

   EXPECT_EQ( connect_status, TC_CONN_DISABLED );

}

TEST_F( TCConnectTest, testNullHostname ) { 

   device->hostname = NULL;

   int connect_status = tc_connect( device );

   EXPECT_EQ( connect_status, TC_CONN_DISABLED );
}

