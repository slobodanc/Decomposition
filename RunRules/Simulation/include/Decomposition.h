/**\file */
#ifndef SLIC_DECLARATIONS_Decomposition_H
#define SLIC_DECLARATIONS_Decomposition_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define Decomposition_PCIE_ALIGNMENT (16)
#define Decomposition_FMEM_SIZE (1024)


/*----------------------------------------------------------------------------*/
/*-------------------------- Interface firstKernel ---------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'firstKernel'.
 * 
 * \param [in] param_n Interface Parameter "n".
 * \param [in] instream_input1 The stream should be of size ((param_n + (param_n % 2)) * 8) bytes.
 * \param [in] instream_v The stream should be of size ((param_n + (param_n % 2)) * 8) bytes.
 * \param [out] outstream_output1 The stream should be of size 16 bytes.
 */
void Decomposition_firstKernel(
	int64_t param_n,
	const double *instream_input1,
	const double *instream_v,
	double *outstream_output1);

/**
 * \brief Basic static non-blocking function for the interface 'firstKernel'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_n Interface Parameter "n".
 * \param [in] instream_input1 The stream should be of size ((param_n + (param_n % 2)) * 8) bytes.
 * \param [in] instream_v The stream should be of size ((param_n + (param_n % 2)) * 8) bytes.
 * \param [out] outstream_output1 The stream should be of size 16 bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *Decomposition_firstKernel_nonblock(
	int64_t param_n,
	const double *instream_input1,
	const double *instream_v,
	double *outstream_output1);

/**
 * \brief Advanced static interface, structure for the engine interface 'firstKernel'
 * 
 */
typedef struct { 
	int64_t param_n; /**<  [in] Interface Parameter "n". */
	const double *instream_input1; /**<  [in] The stream should be of size ((param_n + (param_n % 2)) * 8) bytes. */
	const double *instream_v; /**<  [in] The stream should be of size ((param_n + (param_n % 2)) * 8) bytes. */
	double *outstream_output1; /**<  [out] The stream should be of size 16 bytes. */
} Decomposition_firstKernel_actions_t;

/**
 * \brief Advanced static function for the interface 'firstKernel'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void Decomposition_firstKernel_run(
	max_engine_t *engine,
	Decomposition_firstKernel_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'firstKernel'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_firstKernel_run_nonblock(
	max_engine_t *engine,
	Decomposition_firstKernel_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'firstKernel'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void Decomposition_firstKernel_run_group(max_group_t *group, Decomposition_firstKernel_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'firstKernel'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_firstKernel_run_group_nonblock(max_group_t *group, Decomposition_firstKernel_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'firstKernel'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void Decomposition_firstKernel_run_array(max_engarray_t *engarray, Decomposition_firstKernel_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'firstKernel'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_firstKernel_run_array_nonblock(max_engarray_t *engarray, Decomposition_firstKernel_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* Decomposition_firstKernel_convert(max_file_t *maxfile, Decomposition_firstKernel_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*-------------------------- Interface secondKernel --------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'secondKernel'.
 * 
 * \param [in] param_n Interface Parameter "n".
 * \param [in] instream_input2 The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes.
 * \param [out] outstream_output2 The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes.
 */
void Decomposition_secondKernel(
	int64_t param_n,
	const double *instream_input2,
	double *outstream_output2);

/**
 * \brief Basic static non-blocking function for the interface 'secondKernel'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_n Interface Parameter "n".
 * \param [in] instream_input2 The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes.
 * \param [out] outstream_output2 The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *Decomposition_secondKernel_nonblock(
	int64_t param_n,
	const double *instream_input2,
	double *outstream_output2);

/**
 * \brief Advanced static interface, structure for the engine interface 'secondKernel'
 * 
 */
typedef struct { 
	int64_t param_n; /**<  [in] Interface Parameter "n". */
	const double *instream_input2; /**<  [in] The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes. */
	double *outstream_output2; /**<  [out] The stream should be of size (((param_n * param_n) + (param_n % 2)) * 8) bytes. */
} Decomposition_secondKernel_actions_t;

/**
 * \brief Advanced static function for the interface 'secondKernel'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void Decomposition_secondKernel_run(
	max_engine_t *engine,
	Decomposition_secondKernel_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'secondKernel'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_secondKernel_run_nonblock(
	max_engine_t *engine,
	Decomposition_secondKernel_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'secondKernel'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void Decomposition_secondKernel_run_group(max_group_t *group, Decomposition_secondKernel_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'secondKernel'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_secondKernel_run_group_nonblock(max_group_t *group, Decomposition_secondKernel_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'secondKernel'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void Decomposition_secondKernel_run_array(max_engarray_t *engarray, Decomposition_secondKernel_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'secondKernel'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_secondKernel_run_array_nonblock(max_engarray_t *engarray, Decomposition_secondKernel_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* Decomposition_secondKernel_convert(max_file_t *maxfile, Decomposition_secondKernel_actions_t *interface_actions);



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] ticks_DecompositionKernel1 The number of ticks for which kernel "DecompositionKernel1" will run.
 * \param [in] ticks_DecompositionKernel2 The number of ticks for which kernel "DecompositionKernel2" will run.
 * \param [in] inscalar_DecompositionKernel1_n Input scalar parameter "DecompositionKernel1.n".
 * \param [in] inscalar_DecompositionKernel2_n Input scalar parameter "DecompositionKernel2.n".
 * \param [in] instream_input1 Stream "input1".
 * \param [in] instream_size_input1 The size of the stream instream_input1 in bytes.
 * \param [in] instream_input2 Stream "input2".
 * \param [in] instream_size_input2 The size of the stream instream_input2 in bytes.
 * \param [in] instream_v Stream "v".
 * \param [in] instream_size_v The size of the stream instream_v in bytes.
 * \param [out] outstream_output1 Stream "output1".
 * \param [in] outstream_size_output1 The size of the stream outstream_output1 in bytes.
 * \param [out] outstream_output2 Stream "output2".
 * \param [in] outstream_size_output2 The size of the stream outstream_output2 in bytes.
 */
void Decomposition(
	uint64_t ticks_DecompositionKernel1,
	uint64_t ticks_DecompositionKernel2,
	uint64_t inscalar_DecompositionKernel1_n,
	uint64_t inscalar_DecompositionKernel2_n,
	const void *instream_input1,
	size_t instream_size_input1,
	const void *instream_input2,
	size_t instream_size_input2,
	const void *instream_v,
	size_t instream_size_v,
	void *outstream_output1,
	size_t outstream_size_output1,
	void *outstream_output2,
	size_t outstream_size_output2);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] ticks_DecompositionKernel1 The number of ticks for which kernel "DecompositionKernel1" will run.
 * \param [in] ticks_DecompositionKernel2 The number of ticks for which kernel "DecompositionKernel2" will run.
 * \param [in] inscalar_DecompositionKernel1_n Input scalar parameter "DecompositionKernel1.n".
 * \param [in] inscalar_DecompositionKernel2_n Input scalar parameter "DecompositionKernel2.n".
 * \param [in] instream_input1 Stream "input1".
 * \param [in] instream_size_input1 The size of the stream instream_input1 in bytes.
 * \param [in] instream_input2 Stream "input2".
 * \param [in] instream_size_input2 The size of the stream instream_input2 in bytes.
 * \param [in] instream_v Stream "v".
 * \param [in] instream_size_v The size of the stream instream_v in bytes.
 * \param [out] outstream_output1 Stream "output1".
 * \param [in] outstream_size_output1 The size of the stream outstream_output1 in bytes.
 * \param [out] outstream_output2 Stream "output2".
 * \param [in] outstream_size_output2 The size of the stream outstream_output2 in bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *Decomposition_nonblock(
	uint64_t ticks_DecompositionKernel1,
	uint64_t ticks_DecompositionKernel2,
	uint64_t inscalar_DecompositionKernel1_n,
	uint64_t inscalar_DecompositionKernel2_n,
	const void *instream_input1,
	size_t instream_size_input1,
	const void *instream_input2,
	size_t instream_size_input2,
	const void *instream_v,
	size_t instream_size_v,
	void *outstream_output1,
	size_t outstream_size_output1,
	void *outstream_output2,
	size_t outstream_size_output2);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t ticks_DecompositionKernel1; /**<  [in] The number of ticks for which kernel "DecompositionKernel1" will run. */
	uint64_t ticks_DecompositionKernel2; /**<  [in] The number of ticks for which kernel "DecompositionKernel2" will run. */
	uint64_t inscalar_DecompositionKernel1_n; /**<  [in] Input scalar parameter "DecompositionKernel1.n". */
	uint64_t inscalar_DecompositionKernel2_n; /**<  [in] Input scalar parameter "DecompositionKernel2.n". */
	const void *instream_input1; /**<  [in] Stream "input1". */
	size_t instream_size_input1; /**<  [in] The size of the stream instream_input1 in bytes. */
	const void *instream_input2; /**<  [in] Stream "input2". */
	size_t instream_size_input2; /**<  [in] The size of the stream instream_input2 in bytes. */
	const void *instream_v; /**<  [in] Stream "v". */
	size_t instream_size_v; /**<  [in] The size of the stream instream_v in bytes. */
	void *outstream_output1; /**<  [out] Stream "output1". */
	size_t outstream_size_output1; /**<  [in] The size of the stream outstream_output1 in bytes. */
	void *outstream_output2; /**<  [out] Stream "output2". */
	size_t outstream_size_output2; /**<  [in] The size of the stream outstream_output2 in bytes. */
} Decomposition_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void Decomposition_run(
	max_engine_t *engine,
	Decomposition_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_run_nonblock(
	max_engine_t *engine,
	Decomposition_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void Decomposition_run_group(max_group_t *group, Decomposition_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_run_group_nonblock(max_group_t *group, Decomposition_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void Decomposition_run_array(max_engarray_t *engarray, Decomposition_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *Decomposition_run_array_nonblock(max_engarray_t *engarray, Decomposition_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* Decomposition_convert(max_file_t *maxfile, Decomposition_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* Decomposition_init(void);

/* Error handling functions */
int Decomposition_has_errors(void);
const char* Decomposition_get_errors(void);
void Decomposition_clear_errors(void);
/* Free statically allocated maxfile data */
void Decomposition_free(void);
/* returns: -1 = error running command; 0 = no error reported */
int Decomposition_simulator_start(void);
/* returns: -1 = error running command; 0 = no error reported */
int Decomposition_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_Decomposition_H */

