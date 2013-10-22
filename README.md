### ZipArchive

This is a rendition of which has been modified by Robert M. Ryan on October 21, 2013:

1. Include ARC support

2. Conform to [Cocoa Naming Conventions](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/CodingGuidelines/Articles/NamingMethods.html).

3. Upgrade Minizip from 1.01e to 1.01h

4. Minor fixes, including:

   - Delegate methods were not getting called because of missing colon in `@respondsToSelector`;
 
   - Replaced long since deprecated methods with current ones; and
 
   - Tweaked code to prevent immaterial compiler warnings.
   
   - Remove "2" from ZIP creation method names.

For more documentation and example, please see the [Class Hierarchy](http://robertmryan.github.io/ZipArchive/Classes/ZipArchive.html).

### License

This is distributed in conformance with the MIT License (MIT)

> Copyright (c) 2008 aish
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in
> all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
> THE SOFTWARE.
