/* Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty. This file is offered as-is,
 * without any warranty.
 */

/*! @file mainstate.h
 * @brief Definitions for main state machine
	************************************************************************/
	
#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "template.h"

enum MainStateEvents {
	FRAMESEQ_EVT,       /* frame ready to process (before setting up next frame capture) */
	FRAMEPAR_EVT,       /* frame ready to process (parallel to next capture) */
	IPC_GET_APP_STATE_EVT, /* Webinterface asks for the current application state. */
	IPC_GET_THRESHOLD_IMG_EVT, /* Webinterface asks for a color image. */
	IPC_GET_RAW_IMG_EVT, /* Webinterface asks for a raw image. */
	IPC_SET_SHOWIMG_MODE_EVT /* Webinterface wants to set whether we capture color or raw images. */
};


/*typedef struct MainState MainState;*/
typedef struct MainState {
	Hsm super;
	State showRaw, showThreshold;
} MainState;


void MainStateConstruct(MainState *me);


#endif /*MAINSTATE_H*/
