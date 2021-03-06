/*
	Copyright (c) 2005 BEA Systems, Inc.
	All rights reserved

	THIS IS UNPUBLISHED PROPRIETARY
	SOURCE CODE OF BEA Systems, Inc.
	The copyright notice above does not
	evidence any actual or intended
	publication of such source code.
*/
/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log: DOMTreeErrorReporter.cpp,v $
 * Revision 1.6  2005/04/20 09:42:59  beadev
 * CR#222952# update copyright
 *
 * Revision 1.5  2005/03/08 06:30:28  swang
 * CR#212471# Update using Xerces 2.5
 *
 * Revision 1.4  2002/09/03 20:29:57  wparsons
 * CR#000198# copyright and path fixes to samples files
 *
 * Revision 1.3  2002/09/03 19:26:34  bhavani
 * CR#CR084169# change path in #include directive
 *
 * Revision 1.2  2002/08/29 14:45:31  wparsons
 * CR#000198# copyright and path fixes to samples files
 *
 * Revision 1.1  2002/05/01 19:38:19  bhavani
 * CR#CR062582# xml sample
 *
 * Revision 1.9  2001/05/11 13:24:53  tng
 * Copyright update.
 *
 * Revision 1.8  2001/05/04 19:01:05  tng
 * DOMPrint fix.  Check error before continuing.
 *
 * Revision 1.7  2001/05/03 15:59:32  tng
 * Schema: samples update with schema
 *
 * Revision 1.6  2000/08/24 22:36:22  andyh
 * Fix DOMPrint crash when input xml file is not found.
 *
 * Revision 1.5  2000/05/15 22:31:06  andyh
 * Replace #include<memory.h> with <string.h> everywhere.
 *
 * Revision 1.4  2000/03/02 19:53:40  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/06 07:47:18  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  1999/12/03 00:14:53  andyh
 * Removed transcoding stuff, replaced with DOMString::transcode.
 *
 * Tweaked xml encoding= declaration to say ISO-8859-1.  Still wrong,
 * but not as wrong as utf-8
 *
 * Revision 1.1.1.1  1999/11/09 01:09:51  twl
 * Initial checkin
 *
 * Revision 1.6  1999/11/08 20:43:35  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/sax/SAXParseException.hpp>
#include "DOMTreeErrorReporter.hpp"
#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif
#include <stdlib.h>
#include <string.h>

void DOMTreeErrorReporter::warning(const SAXParseException&)
{
    //
    // Ignore all warnings.
    //
}

void DOMTreeErrorReporter::error(const SAXParseException& toCatch)
{
    fSawErrors = true;
    XERCES_STD_QUALIFIER cerr << "Error at file \"" << XMLString::transcode(toCatch.getSystemId())
		 << "\", line " << toCatch.getLineNumber()
		 << ", column " << toCatch.getColumnNumber()
         << "\n   Message: " << XMLString::transcode(toCatch.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void DOMTreeErrorReporter::fatalError(const SAXParseException& toCatch)
{
    fSawErrors = true;
    XERCES_STD_QUALIFIER cerr << "Fatal Error at file \"" << XMLString::transcode(toCatch.getSystemId())
		 << "\", line " << toCatch.getLineNumber()
		 << ", column " << toCatch.getColumnNumber()
         << "\n   Message: " << XMLString::transcode(toCatch.getMessage()) << XERCES_STD_QUALIFIER endl;
}

void DOMTreeErrorReporter::resetErrors()
{
    // No-op in this case
}


