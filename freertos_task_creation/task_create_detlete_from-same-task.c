/* Include files */
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"

/* Task function prototypes */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

/* Task handle for Task 2 */
TaskHandle_t xTask2Handle = NULL;

/* Task parameters */
const char *pvTask1 = "Task1 is running.";
const char *pvTask2 = "Task2 is running.";

/* Extern functions */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

int main( void )
{
    /* Board initializations */
    SystemInit();
    SystemCoreClockUpdate();
    printf("Initialization is done.\r\n");

    /* Create Task 2 first and store its handle */
    xTaskCreate(vTask2,          /* Task function */
                "Task 2",        /* Task name */
                configMINIMAL_STACK_SIZE, 
                (void*)pvTask2,  /* Parameter */
                1,               /* Priority */
                &xTask2Handle ); /* Store handle */

    /* Create Task 1 */
    xTaskCreate(vTask1,
                "Task 1",
                configMINIMAL_STACK_SIZE,
                (void*)pvTask1,
                1,
                NULL );

    /* Start the scheduler */
    vTaskStartScheduler();

    /* Should never reach here */
    for( ;; );
}

/*-----------------------------------------------------------*/
void vTask1( void *pvParameters )
{
    char *pcTaskName = (char *) pvParameters;

    for( ;; )
    {
        printf("%s\r\n", pcTaskName);

        /* Delay for 100 ticks */
        vTaskDelay(100);

        /* Delete Task 2 */
        if(xTask2Handle != NULL)
        {
            printf("Deleting Task 2...\r\n");
            vTaskDelete(xTask2Handle);
            xTask2Handle = NULL; // Clear the handle
        }
    }
}

/*-----------------------------------------------------------*/
void vTask2( void *pvParameters )
{
    char *pcTaskName = (char *) pvParameters;

    for( ;; )
    {
        printf("%s\r\n", pcTaskName);

        /* Delay for 100 ticks */
        vTaskDelay(100);
    }
}

