//
//  Macros.h
//
//  Created by Bob de Graaf on 07-07-13.
//  Copyright (c) 2013 GraafICT. All rights reserved.
//

//Simple macros
#define nsprefs                 [NSUserDefaults standardUserDefaults]
#define iPhone5                 ([[UIScreen mainScreen] bounds].size.height == 568.0)
#define iOS6                    ([[UIDevice currentDevice] systemVersion].floatValue >= 6.0)
#define isPad                   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define isPortrait              UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)

//Formulas/conversions
#define radians(degrees)        degrees * M_PI / 180
#define convertToCm(inch)       inch*2.54
#define convertToKg(lbs)        lbs/2.2
#define convertToInch(cm)       cm/2.54
#define convertToLbs(kg)        kg*2.2

//Singletons
#import "AppDelegate.h"
#define pDel                    ((AppDelegate *)[[UIApplication sharedApplication] delegate])

//Folders
#define tempFolder              NSTemporaryDirectory()
#define docFolder               [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

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