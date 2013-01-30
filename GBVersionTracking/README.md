 Call this in application:didFinishLaunching:withOptions:
 [GBVersionTracking track];
 
 Call this anywhere
 l(@"First launch ever?: %@", _b([GBVersionTracking isFirstLaunchEver]));
 l(@"First launch for this version?: %@", _b([GBVersionTracking isFirstLaunchForVersion]));
 l(@"First launch for this build?: %@", _b([GBVersionTracking isFirstLaunchForBuild]));
 
 l(@"Current version: %@", [GBVersionTracking currentVersion]);
 l(@"Previous version: %@", [GBVersionTracking previousVersion]);
 l(@"Version history: %@", [GBVersionTracking versionHistory]);
 
 l(@"Current build: %@", [GBVersionTracking currentBuild]);
 l(@"Previous build: %@", [GBVersionTracking previousBuild]);
 l(@"Build history: %@", [GBVersionTracking buildHistory]);
 
 Required libraries (add dependency, link, -ObjC linker flag, header search path in superproject):
 * GBToolbox
 * GBAnalytics
 * GBVersionTracking