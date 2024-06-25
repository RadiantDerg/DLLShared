#pragma once

#ifndef _MESSAGE_COMMON
#define _MESSAGE_COMMON

#pragma region RGBA f32 Colors
#define GUI_TEXTCOLOR_DEFAULT	{1.00f, 1.00f, 1.00f, 1.00f} // White
#define GUI_TEXTCOLOR_COMMENT	{0.34f, 0.65f, 0.29f, 1.00f} // VS Comment Green 
#define GUI_TEXTCOLOR_INFO		{0.00f, 1.00f, 0.00f, 1.00f} // Light Green
#define GUI_TEXTCOLOR_NOTICE	{1.00f, 0.80f, 0.00f, 1.00f} // Yellow
#define GUI_TEXTCOLOR_WARN		{1.00f, 0.50f, 0.00f, 1.00f} // Orange
#define GUI_TEXTCOLOR_ERROR		{1.00f, 0.00f, 0.00f, 1.00f} // Red
#pragma endregion


#pragma region Message
#define MSG_NOT_IMPL			"Not Implemented"

// Notices
#define MSG_NOTICE_DEFAULT		"NOTICE"
#define MSG_NOTICE_NO_STAGE     "No stage currently loaded"

// Warnings
#define MSG_WARN_DEFAULT		"WARNING"
#define MSG_WARN_EDIT_DISABLE	"Editing has been temporarily disabled to \nprevent acessing invalid memory addresses"

// Errors
#define MSG_ERR_DEFAULT			"ERROR"
#define MSG_ERR_CRITICAL		"CRITICAL ERROR"

#pragma endregion
#endif // _MESSAGE_COMMON