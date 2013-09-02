// Copyright (c) 2013 Philip M. Hubbard
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// http://opensource.org/licenses/MIT

//
// AutAlert.h
//
// Routines for that let a library report warnings and errors, and which let an
// application specify functions for reporting those warnings and errors.
//

#ifndef __AutAlert__
#define __AutAlert__

#include <string>
#include <functional>

namespace Aut
{
    // Report a warning or error.  The text will be displayed (somehow) by the
    // routines specified by the application.
    
    void    warning(const std::string& text);
    void    error(const std::string& text);
    void    fatalError(const std::string& text);
    
    // Set and get the routines that report the warning and error text.  The
    // routine for a fatal error is responsible for terminating the application
    // in an appropriate way (e.g., calling abort()).  The default versions of
    // these functions write the text to std::cerr, with the version for fatal
    // errors then calling abort().
    
    void    setWarningFunction(std::function<void(const std::string&)>);
    void    setErrorFunction(std::function<void(const std::string&)>);
    void    setFatalErrorFunction(std::function<void(const std::string&)>);
    
    std::function<void(const std::string&)> warningFunction();
    std::function<void(const std::string&)> errorFunction();
    std::function<void(const std::string&)> fatalErrorFunction();
}

#endif
