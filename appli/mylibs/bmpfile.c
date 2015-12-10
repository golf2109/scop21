/**
 * \file bmpfile.c
 * \brief Contient le header Bitmap utilis� pour que l'image soit reconnue sous Windows / Unix
 * \author Fran�ois Leparoux
 * \version 1.2
 */


#include "bmpfile.h"

const unsigned char BMP_HEADER[BMP_HEADER_SIZE] = {

		// File header
		0x42,0x4d, 				//   BM header
		0x36,0x84,0x03,0x00, 	// * BMP Size : 0x1836 = W(64) * H(32) * Depth(3) + Header(54)
		0x00,0x00, 				//   Application specific
		0x00,0x00, 				//   Application specific
		0x36,0x00,0x00,0x00, 	//   0x36 = 54 (header)
		0x28,0x00,0x00,0x00, 	//   DIB Header bytes from this point
		0x40,0x01,0x00,0x00, 	// * Width  (0x40 = 64 pixels)
		0xF0,0x00,0x00,0x00, 	// * Height (0x20 = 32 pixels)
		0x01,0x00, 				//   1 plane
		0x18,0x00,				//   0x18 = 24 bits per pixel (3 bytes)
		0x00,0x00,0x00,0x00,	//   No compression
		0x00,0x84,0x03,0x00,	// * 0x1800 = W(64) * H(32) * Depth(3)
		0x00,0x00,0x00,0x00,	//   Resolution (horizontal)
		0x00,0x00,0x00,0x00,	//   			  (vertical)
		0x00,0x00,0x00,0x00,	//   0 colors in palette
		0x00,0x00,0x00,0x00		//   all colors are important
};