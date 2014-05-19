//
//  BDGMacros.h
//
//  Created by Bob de Graaf on 07-07-12.
//  Copyright (c) 2014 GraafICT. All rights reserved.
//

//Simple macros
#define nsprefs                 [NSUserDefaults standardUserDefaults]
#define iPhone5                 ([[UIScreen mainScreen] bounds].size.height == 568.0)
#define isPad                   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define iOS5                    ([[UIDevice currentDevice] systemVersion].floatValue >= 5.0)
#define iOS6                    ([[UIDevice currentDevice] systemVersion].floatValue >= 6.0)
#define iOS7                    ([[UIDevice currentDevice] systemVersion].floatValue >= 7.0)
#define isPortrait              UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)

//Formulas/conversions
#define convertToLbs(kg)        kg*2.2
#define convertToInch(cm)       cm/2.54
#define convertToKg(lbs)        lbs/2.2
#define convertToCm(inch)       inch*2.54
#define radians(degrees)        degrees * M_PI / 180

//Day/Week/Month/Year in seconds
#define kMinuteInSeconds        60
#define kHourInSeconds          3600
#define kDayInSeconds           86400
#define kWeekInSeconds          604800

//Folders
#define tempFolder              NSTemporaryDirectory()
#define docFolder               [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

//AppName
#define LOCALIZED_APP_NAME      [[[NSBundle mainBundle] localizedInfoDictionary] objectForKey:@"CFBundleDisplayName"]
#define APPNAME                 LOCALIZED_APP_NAME ? LOCALIZED_APP_NAME : [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

//Show messages
#define showM1(MSG)             [[[UIAlertView alloc] initWithTitle:APPNAME message:(MSG) delegate:nil cancelButtonTitle:NSLocalizedString(@"OK",@"") otherButtonTitles:nil] show]
#define showM2(TITLE,MSG)       [[[UIAlertView alloc] initWithTitle:(TITLE) message:(MSG) delegate:nil cancelButtonTitle:NSLocalizedString(@"OK",@"") otherButtonTitles:nil] show]

//Logfonts
#define logAllFonts             for(NSString *fontFamilyStrings in [UIFont familyNames]) { \
NSLog(@"Font family: %@", fontFamilyStrings); \
for(NSString *fontStrings in [UIFont fontNamesForFamilyName:fontFamilyStrings]) { \
NSLog(@"-- Font: %@", fontStrings); \
} \
}

//Debug log
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

//Singleton GCD
#ifndef SINGLETON_GCD
#define SINGLETON_GCD(classname)                        \
\
+ (classname *)shared##classname {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * shared##classname = nil;\
dispatch_once( &pred, ^{                            \
shared##classname = [[self alloc] init]; });    \
return shared##classname;                           \
}
#endif

//Suppress warning performselector
#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

//Suppress warning deprecated
#define SuppressDeprecatedWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)