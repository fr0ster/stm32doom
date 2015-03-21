/*
 * usb_msc_host.c
 *
 *  Created on: 21.03.2015
 *      Author: Florian
 */


/*---------------------------------------------------------------------*
 *  include files                                                      *
 *---------------------------------------------------------------------*/

#include "usb_msc_host.h"
#include "usbh_usr.h"

/*---------------------------------------------------------------------*
 *  local definitions                                                  *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  external declarations                                              *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  public data                                                        *
 *---------------------------------------------------------------------*/

usb_msc_host_status_t	usb_msc_host_status;
USB_OTG_CORE_HANDLE		USB_OTG_Core;
USBH_HOST				USB_Host;

/*---------------------------------------------------------------------*
 *  private data                                                       *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  private functions                                                  *
 *---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*
 *  public functions                                                   *
 *---------------------------------------------------------------------*/

void usb_msc_host_init (void)
{
	usb_msc_host_status = USB_MSC_DEV_DETACHED;

	USBH_Init (&USB_OTG_Core, USB_OTG_HS_CORE_ID, &USB_Host, &USBH_MSC_cb, &USR_Callbacks);
}

usb_msc_host_status_t usb_msc_host_main (void)
{
	if (usb_msc_host_status != USB_MSC_DEV_NOT_SUPPORTED)
	{
		USBH_Process (&USB_OTG_Core, &USB_Host);
	}

	return usb_msc_host_status;
}

/*---------------------------------------------------------------------*
 *  eof                                                                *
 *---------------------------------------------------------------------*/