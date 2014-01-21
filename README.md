GBVersionTracking
============

Track which versions of your iOS or Mac OS X app a user has previously installed.

Usage
------------

Call this on each app launch inside `application:didFinishLaunching:withOptions:` (iOS), or `-applicationDidFinishLaunching:` (OS X)

```objective-c
[GBVersionTracking track];
```

Then call these whenever you want (in these examples the user has launched a bunch of previous versions, and this is the first time he's launched version 3.0):

```objective-c
[GBVersionTracking isFirstLaunchEver];				//Returns: NO
[GBVersionTracking isFirstLaunchForVersion];		//Returns: YES
[GBVersionTracking isFirstLaunchForBuild];			//Returns: YES
 
[GBVersionTracking currentVersion];					//Returns: @"3.0"
[GBVersionTracking previousVersion];				//Returns: @"2.1"
[GBVersionTracking versionHistory];					//Returns: [@"1.0", @"2.0", @"2.1", @"3.0"]
 
[GBVersionTracking currentBuild];					//Returns: @"3000"
[GBVersionTracking previousBuild];					//Returns: @"2102"
[GBVersionTracking buildHistory];					//Returns: [@"1000", @"2043", @"2107", @"3004"]
 ```

N.B.: The build and version numbers are whatever you define in your app's Info.plist

Don't forget to import header:

```objective-c
#import <GBVersionTracking/GBVersionTracking.h>
```

Installation
------------

Use CocoaPods, add this to your project's Podfile and run `pod update`:

```
pod 'GBVersionTracking'
```

Copyright & License
------------

Copyright 2013 Luka Mirosevic

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this work except in compliance with the License. You may obtain a copy of the License in the LICENSE file, or at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/lmirosevic/gbversiontracking/trend.png)](https://bitdeli.com/free "Bitdeli Badge")
