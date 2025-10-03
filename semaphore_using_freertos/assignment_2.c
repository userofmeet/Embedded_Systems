/* Include files */
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"								// EC080
#include "semphr.h"
/* The task functions prototype*/
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
void vTask3( void *pvParameters );
SemaphoreHandle_t xSemaphore_pri;
/* Task parameter to be sent to the task function */
const char *pvTask1 = "Task1 is running.";
const char *pvTask2 = "Task2 is running.";
const char *pvTask3 = "Task3 is running";
/* Extern functions */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
int main( void )
{
	/* Board initializations */
	 SystemInit();
	/* This function initializes the MCU clock, PLL will be used to generate Main MCU clock */
	SystemCoreClockUpdate();
	printf("Initialization is done.\r\n");
	/* Create one of the two tasks. */
	xTaskCreate(vTask1, /* Pointer to the function that implements the task. */
	"Task 1", /* Text name for the task. This is to facilitate debugging only. */
	 configMINIMAL_STACK_SIZE, /* Stack depth in words. */
	(void*)pvTask1, /* We are not using the task parameter. */
	1, /* This task will run at priority 1. */
	NULL ); /* We are not using the task handle. */
	 /* Create the other task in exactly the same way. */
	xTaskCreate( vTask2, "Task 2", configMINIMAL_STACK_SIZE, (void*)pvTask2, 2, NULL );
	xTaskCreate( vTask3, "Task 3", configMINIMAL_STACK_SIZE, (void*)pvTask3, 3, NULL);
	/* Start the scheduler so our tasks start executing. */
	xSemaphore_pri = xSemaphoreCreateBinary();
	 xSemaphoreGive(xSemaphore_pri);
	vTaskStartScheduler();
	/* If all is well we will never reach here as the scheduler will now be
	running. If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/
void vTask1( void *pvParameters )
{
	char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		if(xSemaphoreTake(xSemaphore_pri,portMAX_DELAY)==pdTRUE)
		{
			/* Print out the name of this task. */
			 printf( "%s\r\n",pcTaskName );
		//	vTaskDelay( 10 );
			xSemaphoreGive(xSemaphore_pri);
			/* Delay for a period. */
		}
		//vTaskDelay( 10);
	}
}

/*-----------------------------------------------------------*/
void vTask2( void *pvParameters )
{
	char *pcTaskName = (char *) pvParameters;
	/* Task is implemented in an infinite loop. */
	for( ;; )
	{
		if(xSemaphoreTake(xSemaphore_pri,portMAX_DELAY)==pdTRUE)
		{
			/* Print out the name of this task. */
			 printf( "%s\r\n",pcTaskName );
			xSemaphoreGive(xSemaphore_pri);
			vTaskDelay( 10);
		}
	  vTaskDelay( 20 );
	}
}

void vTask3( void *pvParameters) 
{
	char *pcTaskName = (char *) pvParameters;
	for(;;)
	{
		if(xSemaphoreTake(xSemaphore_pri, portMAX_DELAY) == pdTRUE)
		{
			printf("%s\r\n",pcTaskName);
			xSemaphoreGive(xSemaphore_pri);
			vTaskDelay(10);
		}
		vTaskDelay(30);
	}
}
