/*******************************************************************************/
/**
\file       app_scheduler.c
\brief      Multi-thread Task scheduler.
\author     Abraham Tezmol
\version    0.1
\date       09/09/2008
*/

/** Variable types and common definitions */
#include "system_samv71.h"

/** Scheduler function prototypes definitions */
#include "app_scheduler.h"
/** Tasks definition */
#include "app_tasks.h"
/** Real Time timer resource assigned as scheduler tick */
#include "../SysTick/systick.h"


/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/

uint8_t gu8Scheduler_Status;
uint8_t gu8Scheduler_Counter;

tSchedulerTasks_ID TaskScheduler_Task_ID_Activated;
tSchedulerTasks_ID TaskScheduler_Task_ID_Running;
tSchedulerTasks_ID TasksScheduler_Task_ID_Backup;

uint16_t u16_1s_Counter;
uint16_t u16_2s_Counter;
uint16_t u16_3s_Counter;
uint16_t u16_8s_Counter;


tSchedulingTask TimeTriggeredTasks[TASK_SCH_MAX_NUMBER_TIME_TASKS] =
{ 
    {TASKS_1,  TASKS_LIST_3S,  SUSPENDED, 3},
    {TASKS_2,  TASKS_LIST_1S,  SUSPENDED, 1},
    {TASKS_3,  TASKS_LIST_2S,  SUSPENDED, 2},
    {TASKS_4,  TASKS_LIST_8S,  SUSPENDED, 4},
};

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/


/*****************************************************************************************************
* Code of module wide private FUNCTIONS
*****************************************************************************************************/
void vfnScheduler_Callback(void);

/*****************************************************************************************************
* Code of public FUNCTIONS
*****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief    Scheduler - Initialization
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo     
*/
void vfnScheduler_Init(void)
{    
    /* Init Global and local Task Scheduler variables */
    gu8Scheduler_Counter   = 0u;
    TaskScheduler_Task_ID_Activated = TASK_NULL;
    TaskScheduler_Task_ID_Running = TASK_NULL;
    TasksScheduler_Task_ID_Backup = TASK_NULL;
    u16_1s_Counter        = 0u;
    u16_2s_Counter        = 0u;
    u16_3s_Counter        = 0u;
    u16_8s_Counter        = 0u;
    gu8Scheduler_Status    = TASK_SCHEDULER_INIT;
}

/*******************************************************************************/
/**
* \brief    Scheduler Start - Once time base is armed, start execution of   \n
            Multi-thread Round Robin scheduling scheme.                     \n
            This function requires prior execution of "vfnScheduler_Init"
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo     
*/
void vfnScheduler_Start(void)
{
	if (sysTick_init(TASK_SCHEDULER_BASE_FREQ, vfnScheduler_Callback)) 
	{
		while (1);
	}
    gu8Scheduler_Status = TASK_SCHEDULER_RUNNING;
}

/*******************************************************************************/
/**
* \brief    Scheduler Stop - stop execution of Multi-thread Round Robin scheduling scheme.
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo     
*/
void vfnScheduler_Stop(void)
{  
    /* Update scheduler status accordingly */
    gu8Scheduler_Status = TASK_SCHEDULER_HALTED;
}

/***************************************************************************************************/
/**
* \brief    Scheduler - execution of time or event driven tasks
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo     
*/
void vfnScheduler_TaskStart( tSchedulingTask * Task )
{
    /* Indicate that this Task has gained CPU allocation */ 
    Task->enTaskState = RUNNING;
    TaskScheduler_Task_ID_Running =  Task->TaskId;
    /* Perform actual execution of task */
    Task->ptrTask();
    /* Indicate that Task execution has completed */ 
    Task->enTaskState = SUSPENDED;
}

/***************************************************************************************************/
/**
* \brief    Scheduler - activation of time or event driven tasks
* \author   Abraham Tezmol
* \param    Task - pointer to task
* \return   void
* \todo     
*/
void vfnScheduler_TaskActivate( tSchedulingTask * Task )
{ 
    TaskScheduler_Task_ID_Activated = Task->TaskId;
    Task->enTaskState = READY;
}

/*******************************************************************************/
/**
* \brief    Multi-thread round robin task Scheduler  (non-preemtive)        \n
            It calls the different tasks based on the status of             \n   
            "gu8Scheduler_Thread_ID". This variable is modified by          \n
            ISR "vfnScheduler_PIT_Isr"                                        \n
            List of tasks shall be defined @ "tasks.h" file
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo     
*/
void vfnTask_Scheduler(void)
{
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /*  1s execution thread - used to derive two execution threads:                */
    /*  a) 1s thread (high priority tasks)                                         */
    /*  b) 3s thread (lowest priority tasks)                                     */
    /*  As any other thread on this scheduler, all tasks must be executed in <=1ms*/
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    if( ( TaskScheduler_Task_ID_Activated == TASKS_1 )
         || ( TaskScheduler_Task_ID_Activated == TASKS_2 ) )
    {
        /* Make a copy of scheduled task ID */
        TasksScheduler_Task_ID_Backup = TaskScheduler_Task_ID_Activated;

        vfnScheduler_TaskStart (&TimeTriggeredTasks[TASKS_2]);
        if( TaskScheduler_Task_ID_Activated == TASKS_1 )
        {
            vfnScheduler_TaskStart (&TimeTriggeredTasks[TASKS_1]);
        }
        /* Verify that thread execution took less than 1 ms */
        if( TasksScheduler_Task_ID_Backup == TaskScheduler_Task_ID_Activated )
        {
             /* In case execution of all thread took less than 1ms */
            TaskScheduler_Task_ID_Activated = TASK_NULL;
        }
    }
    else
    {
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /*  2s execution thread - used to derive two execution threads:                */
        /*  a) 2s thread (high priority tasks)                                 */
        /*  b) 8s thread (second lowest priority tasks)                               */
        /*  As any other thread on this scheduler, all tasks must be executed in <=1ms*/
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        if( ( TaskScheduler_Task_ID_Activated == TASKS_3 )
             || ( TaskScheduler_Task_ID_Activated == TASKS_4 ) )
        {
            /* Make a copy of scheduled task ID */
            TasksScheduler_Task_ID_Backup = TaskScheduler_Task_ID_Activated;

            vfnScheduler_TaskStart (&TimeTriggeredTasks[TASKS_3]);
            if( TaskScheduler_Task_ID_Activated == TASKS_4 )
            {
                vfnScheduler_TaskStart (&TimeTriggeredTasks[TASKS_4]);
            }
            /* Verify that thread execution took less than 1 ms */
            if( TasksScheduler_Task_ID_Backup == TaskScheduler_Task_ID_Activated )
            {
                 /* In case execution of all thread took less than 1ms */
                TaskScheduler_Task_ID_Activated = TASK_NULL;
            }
        }
    }        
}

/*******************************************************************************/
/**
* \brief    Periodic Interrupt Timer Service routine.                           \n
            This interrupt is the core of the task scheduler.                   \n
            It is executed every 1ms                                          	\n
            It defines 3 basic threads from which other 3 threads are derived:  \n
            a) 1s thread (basic) ->  3s thread (derived)                    \n
            b) 2s thread (basic)-> 8s thread (derived)                     \n
            It partitions core execution time into time slices (1ms each one).\n
            This arrangement assures core will have equal task loading across time.\n   
            For more information on how time slice is assigned to each thread,  \n
            refer to file "S12X Task Scheduler Layout.xls"
* \author   Abraham Tezmol
* \param    void
* \return   void
* \todo
*/

void vfnScheduler_Callback(void)
{
    /*-- Update scheduler control variable --*/
    gu8Scheduler_Counter++;

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /*  1s execution thread - used to derive two execution threads:                */
    /*  a) 1s thread (high priority tasks)                                         */
    /*  b) 3s thread (lowest priority tasks)                                     */
    /*  As any other thread on this scheduler, all tasks must be executed in <=1ms*/
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    u16_1s_Counter++;
    u16_3s_Counter++;
    u16_2s_Counter++;
    u16_8s_Counter++;
    /*-- Allow 3 sec periodic tasks to be executed --*/
    if( u16_3s_Counter >= 3000u )
    {
    	/* Indicate that Task is Ready to be executed */
    	vfnScheduler_TaskActivate(&TimeTriggeredTasks[TASKS_1]);
    	u16_3s_Counter       = 0u;
    }
    /*-- Allow 1 sec periodic tasks to be executed --*/
    if(u16_1s_Counter >= 1000)
    {
    	vfnScheduler_TaskActivate(&TimeTriggeredTasks[TASKS_2]);
    	u16_1s_Counter = 0;
    }

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    /*  2s execution thread - used to derive two execution threads:                */
    /*  a) 2s thread (high priority tasks)                                 */
    /*  b) 8s thread (second lowest priority tasks)                               */
    /*  As any other thread on this scheduler, all tasks must be executed in <=1ms*/
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    /*-- Allow 8 sec periodic tasks to be executed --*/
    if( u16_8s_Counter >= 8000u )
    {
    	vfnScheduler_TaskActivate(&TimeTriggeredTasks[TASKS_4]);
    	u16_8s_Counter = 0u;
    }
    /*-- Allow 2 sec periodic tasks to be executed --*/
    if(u16_2s_Counter >= 2000)
    {
    	vfnScheduler_TaskActivate(&TimeTriggeredTasks[TASKS_3]);
    	u16_2s_Counter = 0;
    }
}
/***************************************************************************************************/
