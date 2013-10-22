//
//  ZipArchive.h
//
//  Created by aish on 2008-9-11.
//  acsolu@gmail.com
//  Copyright 2008
//
//  The MIT License (MIT)
//
//  Copyright (c) 2008 aish
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Modified by Robert Ryan on 2013-10-21
//
// History: 
//    09-11-2008 version 1.0    release
//    10-18-2009 version 1.1    support password protected zip files
//    10-21-2009 version 1.2    fix date bug
//    10-21-2013 version 1.3    support ARC; conform to Cocoa naming conventions; miscellaneous fixes

#import <UIKit/UIKit.h>

#include "minizip/zip.h"
#include "minizip/unzip.h"

/** ZipArchiveDelegate protocol */

@protocol ZipArchiveDelegate <NSObject>
@optional

/** Output error message
 *
 * @param msg The error message
 */

-(void) errorMessage:(NSString*) msg;

/** Overwrite operation
 *
 * @param file The path for the file
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) overWriteOperation:(NSString*) file;

@end


/** Class for creating and unzipping ZIP files
 
 ### Usage

 1. Include `libz.dylib` to your project's "Link Binaries with Libraries" section of the target settings.
 
 2. Import `ZipArchive.h`
 
       #import "ZipArchive.h"

 3. If unzipping file, the code might look like:

       NSString *subdirectory = @"archive";   // the folder name to which you will unzip the files
       NSString *documentsPath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
       NSString *archivePath = [documentsPath stringByAppendingPathComponent:subdirectory];

       ZipArchive *za = [[ZipArchive alloc] init];

       if ([za unzipOpenFile:path]) {
           BOOL ret = [za unzipFileTo:archivePath overwrite:YES];
           NSAssert(ret, @"Unzip failed");
       }

 ### See also
 
 - This is based upon aish's original [ZipArchive class](http://code.google.com/p/ziparchive/)
 - This includes version 1.01h of [Minizip](http://www.winimage.com/zLibDll/minizip.html)
 
 */

@interface ZipArchive : NSObject

/// @name Properties

/** Delegate property */

@property (nonatomic, weak) id delegate;

/// @name Create zip files

/** Create zip file
 *
 * @param zipFile Path of file to create.
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) createZipFile:(NSString*) zipFile;

/** Create zip file with password
 *
 * @param zipFile Path of file to create
 * @param password The password to use when creating the zip file.
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) createZipFile:(NSString*) zipFile password:(NSString*) password;

/** Add file to zip file
 *
 * @param file Path of file to create
 * @param newname The new name of the file
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;

/** Close the zip file
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) closeZipFile;

/// @name Unzip files

/** Open zip file to unzip
 *
 * @param zipFile Path of file to open
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) unzipOpenFile:(NSString*) zipFile;

/** Open zip file to unzip with password
 *
 * @param zipFile Path of file to open
 * @param password The password to use when opening the zip file.
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) unzipOpenFile:(NSString*) zipFile password:(NSString*) password;

/** Unzip zip file to particular path
 *
 * @param path Path of directory to where the files will be unzipped.
 * @param overwrite `BOOL` value indicating whether the files at the path should be overwritten if already found.
 *
 * @return Returns `YES` if successful. `NO` if failure.
 */

-(BOOL) unzipFileTo:(NSString*) path overwrite:(BOOL) overwrite;

/** Close the zip file being unzipped
 *
 * @return Returns `YES` if successful. No if failure.
 */

-(BOOL) unzipCloseFile;

@end
