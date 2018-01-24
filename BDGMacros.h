//
//  BDGMacros.h
//
//  Created by Bob de Graaf on 07-07-12.
//  Copyright (c) 2014 GraafICT. All rights reserved.
//

//Simple macros
#define nsprefs                 [NSUserDefaults standardUserDefaults]
#define iPhone4                 ([[UIScreen mainScreen] bounds].size.height == 480.0)
#define iPhone5                 ([[UIScreen mainScreen] bounds].size.height == 568.0)
#define iPhone5OrSmaller        ([[UIScreen mainScreen] bounds].size.height <= 568.0)
#define iPhone5OrBigger         ([[UIScreen mainScreen] bounds].size.height >= 568.0)
#define iPhone6                 ([[UIScreen mainScreen] bounds].size.height == 667.0)
#define iPhone6OrSmaller        ([[UIScreen mainScreen] bounds].size.height <= 667.0)
#define iPhone6OrBigger         ([[UIScreen mainScreen] bounds].size.height >= 667.0)
#define iPhone6Plus             ([[UIScreen mainScreen] bounds].size.height == 736.0)
#define iPhone6PlusOrSmaller    ([[UIScreen mainScreen] bounds].size.height <= 736.0)
#define iPhoneX                 ([[UIScreen mainScreen] bounds].size.height == 812.0)
#define isPad                   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define iOS5                    ([[UIDevice currentDevice] systemVersion].floatValue >= 5.0)
#define iOS6                    ([[UIDevice currentDevice] systemVersion].floatValue >= 6.0)
#define iOS7                    ([[UIDevice currentDevice] systemVersion].floatValue >= 7.0)
#define iOS8                    ([[UIDevice currentDevice] systemVersion].floatValue >= 8.0)
#define iOS9                    ([[UIDevice currentDevice] systemVersion].floatValue >= 9.0)
#define iOS10                   ([[UIDevice currentDevice] systemVersion].floatValue >= 10.0)
#define iOS11                   ([[UIDevice currentDevice] systemVersion].floatValue >= 11.0)
#define iOS12                   ([[UIDevice currentDevice] systemVersion].floatValue >= 12.0)
#define isPortrait              UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)

//Formulas/conversions
#define convertToLbs(kg)        kg*2.2
#define convertToInch(cm)       cm/2.54
#define convertToKg(lbs)        lbs/2.2
#define convertToCm(inch)       inch*2.54
#define radians(degrees)        degrees * M_PI / 180
#define degrees(radians)        radians * 180 / M_PI

//Day/Week/Month/Year in seconds
#define kMinuteInSeconds        60
#define kHourInSeconds          3600
#define kDayInSeconds           86400
#define kWeekInSeconds          604800

//Shared instance shortcuts
#define NOTIFICATION_CENTER     [NSNotificationCenter defaultCenter]
#define FILE_MANAGER            [NSFileManager defaultManager]
#define MAIN_BUNDLE             [NSBundle mainBundle]
#define MAIN_THREAD             [NSThread mainThread]
#define MAIN_SCREEN             [UIScreen mainScreen]
#define APPLICATION             [UIApplication sharedApplication]
#define CURRENT_DEVICE          [UIDevice currentDevice]
#define MAIN_RUN_LOOP           [NSRunLoop mainRunLoop]
#define GENERAL_PASTEBOARD      [UIPasteboard generalPasteboard]

//Folders
#define tempFolder              NSTemporaryDirectory()
#define docFolder               [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

//AppName
#define LOCALIZED_APP_NAME      [[[NSBundle mainBundle] localizedInfoDictionary] objectForKey:@"CFBundleDisplayName"]
#define APPNAME                 LOCALIZED_APP_NAME ?: [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

//Show messages
#define showM1(MSG)             [[[UIAlertView alloc] initWithTitle:APPNAME message:(MSG) delegate:nil cancelButtonTitle:NSLocalizedString(@"OK",@"") otherButtonTitles:nil] show]
#define showM2(TITLE,MSG)       [[[UIAlertView alloc] initWithTitle:(TITLE) message:(MSG) delegate:nil cancelButtonTitle:NSLocalizedString(@"OK",@"") otherButtonTitles:nil] show]

#define showM2Manually(TITLE,MSG)\
UIAlertController* kAlertController = [UIAlertController alertControllerWithTitle:(TITLE) message:(MSG) preferredStyle:UIAlertControllerStyleAlert];\
[kAlertController addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];\

//Logfonts
#define logAllFonts             for(NSString *fontFamilyStrings in [UIFont familyNames]) { \
NSLog(@"Font family: %@", fontFamilyStrings); \
for(NSString *fontStrings in [UIFont fontNamesForFamilyName:fontFamilyStrings]) { \
NSLog(@"-- Font: %@", fontStrings); \
} \
}

//UIColor from HEX (if you have a #, simply replace it by 0x)
#define UIColorFromRGB(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >>  8))/255.0 \
blue:((float)((rgbValue & 0x0000FF) >>  0))/255.0 \
alpha:1.0]

//LogSimulator Docfolder
#define logSimDoc NSLog(@"Documents Directory: %@", [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject]);

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


//Only having this for swift module
#import <Foundation/Foundation.h>
@interface BDGMacros : NSObject
{
    
}

@end
