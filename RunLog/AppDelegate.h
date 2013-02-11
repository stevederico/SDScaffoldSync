//
//  AppDelegate.h
//  RunLog
//
//  Created by Steve Derico on 2/10/13.
//  Copyright (c) 2013 Bixby Apps. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RunLogIncrementalStore.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;

@property (strong, nonatomic) UINavigationController *navigationController;

@end
