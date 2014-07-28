//
//  TreasureData.h
//  TreasureData
//
//  Created by Mitsunori Komatsu on 5/19/14.
//  Copyright (c) 2014 Treasure Data Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TreasureData : NSObject

@property(nonatomic, strong) NSString *defaultDatabase;

+ (void)initializeWithApiKey:(NSString *)apiKey;

+ (instancetype)sharedInstance;

+ (void)initializeApiEndpoint:(NSString *)apiEndpoint;

- (id)initWithApiKey:(NSString *)apiKey;

- (void)setDefaultDatabase:(NSString*)defaultDatabase;

- (void)event:(NSDictionary *)record database:(NSString *)database table:(NSString *)table DEPRECATED_ATTRIBUTE;

- (void)event:(NSDictionary *)record table:(NSString *)table DEPRECATED_ATTRIBUTE;

- (void)addEvent:(NSDictionary *)record database:(NSString *)database table:(NSString *)table;

- (void)addEvent:(NSDictionary *)record table:(NSString *)table;

- (void)addEventWithCallback:(NSDictionary *)record database:(NSString *)database table:(NSString *)table onSuccess:(void (^)())onSuccess onError:(void (^)(NSString*, NSString*))onError;

- (void)addEventWithCallback:(NSDictionary *)record table:(NSString *)table onSuccess:(void (^)())onSuccess onError:(void (^)(NSString*, NSString*))onError;

- (void)uploadWithBlock:(void (^)())block DEPRECATED_ATTRIBUTE;

- (void)uploadEventsWithBlock:(void (^)())block DEPRECATED_ATTRIBUTE;

- (void)uploadEventsWithCallback:(void (^)())onSuccess onError:(void (^)(NSString*, NSString*))onError;

- (void)uploadEvents;

- (void)setApiEndpoint:(NSString*)endpoint DEPRECATED_ATTRIBUTE;

+ (void)disableEventCompression;

+ (void)enableEventCompression;

+ (void)disableLogging;

+ (void)enableLogging;

+ (void)disableTraceLogging;

+ (void)enableTraceLogging;

+ (void)initializeEncryptionKey:(NSString*)encryptionKey;
@end
