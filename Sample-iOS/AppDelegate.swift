//
//  AppDelegate.swift
//  Sample-iOS
//
//  Created by Ignacio Romero on 2017-11-09.
//  Copyright © 2017 Goonbee. All rights reserved.
//

import UIKit
import GBVersionTracking

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, willFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey : Any]? = nil) -> Bool {

        GBVersionTracking.track()

        return true
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        if GBVersionTracking.isFirstLaunchEver() {
            print("First Installed ever! version: \(GBVersionTracking.firstInstalledBuild()) | build: \(GBVersionTracking.firstInstalledVersion())")
        }
        else if GBVersionTracking.isFirstLaunchForVersion() {
            print("First launched version! version: \(GBVersionTracking.currentVersion()) | build: \(GBVersionTracking.currentBuild())")
        }
        else {
            print("No updates! version history: \(GBVersionTracking.versionHistory())")
        }

        return true
    }
}

