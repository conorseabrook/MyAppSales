//
//  SynchingManager.h
//  ASiST
//
//  Created by Oliver on 14.09.09.
//  Copyright 2009 Drobnik.com. All rights reserved.
//

#import <Foundation/Foundation.h>



@class App, Country_v1, GenericAccount, Review_v1;
@protocol ReviewScraperDelegate, TranslationScraperDelegate;


@interface SynchingManager : NSObject
{
	NSOperationQueue *queue;
	NSUInteger activeOperations;
}

+ (SynchingManager *) sharedInstance;

// Notifications
- (void) subscribeToNotificationsWithAccount:(GenericAccount *)notificationsAccount;
- (void) unsubscribeToNotificationsWithAccount:(GenericAccount *)notificationsAccount;

// cancelling
- (void) cancelAllOperationsOfClass:(Class)class;
- (void) cancelAllSynching;

// iTunes Review Scraper
- (void) scrapeForApp:(App *)reviewApp country:(Country_v1 *)reviewCountry delegate:(id<ReviewScraperDelegate>)scraperDelegate;

// Translation Downloader
- (void) translateReview:(Review_v1 *)review delegate:(id<TranslationScraperDelegate>)scraperDelegate;
- (void) cancelAllTranslations;

// iTunes Connect Downloader
- (void) downloadForAccount:(GenericAccount *)itcAccount reportsToIgnore:(NSArray *)reportsArray;

- (void) updateIndicators;
- (NSArray *) queuedOperationsOfClass:(Class)opClass;

- (BOOL) hasActiveOperations;

@end
