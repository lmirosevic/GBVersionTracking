GBVersionTracking
============

Track the history of different versions and builds of your app a user has installed or updated to in the past

Usage
------------

First import header:

```objective-c
#import "GBVersionTracking.h"
```

Call this on each app launch in `application:didFinishLaunching:withOptions:`

```objective-c
[GBVersionTracking track];
```

Call this anywhere:
```objective-c
NSLog(@"First launch ever?: %@", _b([GBVersionTracking isFirstLaunchEver]));
NSLog(@"First launch for this version?: %@", _b([GBVersionTracking isFirstLaunchForVersion]));
NSLog(@"First launch for this build?: %@", _b([GBVersionTracking isFirstLaunchForBuild]));
 
NSLog(@"Current version: %@", [GBVersionTracking currentVersion]);
NSLog(@"Previous version: %@", [GBVersionTracking previousVersion]);
NSLog(@"Version history: %@", [GBVersionTracking versionHistory]);
 
NSLog(@"Current build: %@", [GBVersionTracking currentBuild]);
NSLog(@"Previous build: %@", [GBVersionTracking previousBuild]);
NSLog(@"Build history: %@", [GBVersionTracking buildHistory]);
 ```

N.B.: `_b` is a macro from GBToolbox defined as:
```c
#define _b(expression) expression ? @"YES" : @"NO"
```

Dependencies
------------

Add dependency, link, -ObjC linker flag, header search path in superproject.

* GBToolbox

Copyright & License
------------

Copyright 2013 Luka Mirosevic

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this work except in compliance with the License. You may obtain a copy of the License in the LICENSE file, or at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.