//
//  GBVersionTracking.h
//  GBVersionTracking
//
//  Created by Luka Mirosevic on 28/01/2013.
//  Copyright (c) 2013 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GBVersionTracking : NSObject

+(void)track;                       //Call this in application:didFinishLaunching:withOptions:

+(BOOL)isFirstLaunchEver;           //First time ever the app is launched, irrespective of version?
+(BOOL)isFirstLaunchForVersion;     //First time this particular version is being launched?
+(BOOL)isFirstLaunchForBuild;       //First time this particular build is being launched?

+(NSString *)currentVersion;
+(NSString *)previousVersion;
+(NSArray *)versionHistory;

+(NSString *)currentBuild;
+(NSString *)previousBuild;
+(NSArray *)buildHistory;

@end

/* Demo
 
 [GBVersionTracking track];
 
 l(@"current build: %@\nprevios build: %@\ncurrent version: %@\nprevious version: %@\nisFirstLaunchEver: %@\nfirstlaunchforbuild:%@\nfirstlaunchforversion:%@\n", [GBVersionTracking currentBuild], [GBVersionTracking previousBuild], [GBVersionTracking currentVersion], [GBVersionTracking previousVersion], _b([GBVersionTracking isFirstLaunchEver]), _b([GBVersionTracking isFirstLaunchForBuild]), _b([GBVersionTracking isFirstLaunchForVersion]));
 l(@"b his: %@", [GBVersionTracking buildHistory]);
 l(@"v his %@\n\n", [GBVersionTracking versionHistory]);
 
 */
