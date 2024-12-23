/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

#include "stdio.h"
#include "usbstk5515.h"

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Testing Function                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void TEST_execute( Int16 ( *funchandle )( ), char *testname, Int16 testid )
{
    Int16 status;

    /* Display test ID */
    printf( "%02d  Testing %s...\n", testid, testname );

    /* Call test function */
    status = funchandle( );

    /* Check for test fail */
    if ( status != 0 )
    {
        /* Print error message */
        printf( "     FAIL... error code %d... quitting\n", status );

        /* Software Breakpoint to Code Composer */
        SW_BREAKPOINT;
    }
    else
    {
        /* Print error message */
        printf( "    PASS\n" );
    }
}

extern Int16 aic3204_test( );
extern Int16 oled_test( );
extern Int16 led_test( );
extern Int16 norflash_writer( );
extern Int16 norflash_test( );
extern Int16 sd_test( );
extern Int16 switch_test( );
extern Int16 uled_test( );



/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void main( void )
{
    /* Initialize BSL */
    USBSTK5515_init( );

//    printf("EXBUSSEL = %02x\n", SYS_EXBUSSEL);
    
    // TEST_execute( aic3204_test, "AIC3204", 1 );
     TEST_execute( oled_test, "OLED", 1 );
    // TEST_execute( led_test,  "LED", 1 );
    // TEST_execute( norflash_writer, "NOR Flash Writer", 1 );
    // TEST_execute( norflash_test, "NOR Flash", 1 );
    // TEST_execute( sd_test, "SD card", 1 );
     TEST_execute( switch_test, "Switches", 1 );
     TEST_execute( uled_test,  "User LEDs", 1 );



    printf( "\n***ALL Tests Passed***\n" );
    SW_BREAKPOINT;
}
