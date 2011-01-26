/*
 Copyright 2009-2010 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <StoreKit/StoreKit.h>


typedef enum {
    UAInventoryStatusUnloaded = 0,
    UAInventoryStatusPurchaseDisabled,
    UAInventoryStatusDownloading,
    UAInventoryStatusApple,
    UAInventoryStatusLoaded,
    UAInventoryStatusUpdated,
    UAInventoryStatusFailed,
} UAInventoryStatus;

typedef enum {
    ProductTypeAll = 0,
    ProductTypeInstalled = 1,
    ProductTypeUpdated = 2,
    ProductTypeOrigin = 10
} ProductType;

@class Reachability;
@class ASIHTTPRequest;
@class UAProduct;

@interface UAInventory : NSObject<SKProductsRequestDelegate> {

    NSMutableDictionary *products;
    NSMutableArray *keys;
    NSMutableArray *sortedProducts;
    NSMutableArray *updatedProducts;
    NSMutableArray *installedProducts;

    Reachability *hostReach;
    UAInventoryStatus status;
    NSUInteger reloadCount;
    
    NSString *orderBy;
    BOOL orderAscending;
    
    NSString *purchasingProductIdentifier;
}

@property (assign) UAInventoryStatus status;
@property (nonatomic, retain) NSString *orderBy;
@property (nonatomic, retain) NSString *purchasingProductIdentifier;

- (UAInventory*)init;

// status set to UAInventoryStatusDownloading | UAInventoryStatusPurchaseDisabled
- (void)loadInventory;
// status set to UAInventoryStatusApple
- (void)loadInventoryFinished:(ASIHTTPRequest*)request;
// status set to UAInventoryStatusFinished
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response;
// status set to UAInventoryStatusFailed
- (void)loadInventoryFailed:(ASIHTTPRequest *)request;
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error;
// status set to UAInventoryStatusUpdated
- (void)updateInventory;

// reload if failed
- (void)resetReloadCount;
- (void)reloadInventory;
- (void)hostReachStatusChanged:(NSNotification *)notification;

- (void)registerObserver:(id)observer;
- (void)unregisterObserver:(id)observer;

- (NSUInteger)countForType:(ProductType)type;
- (NSArray *)productsForType:(ProductType)type;
- (UAProduct*)productWithIdentifier:(NSString*)productId;
- (BOOL)hasProductWithIdentifier:(NSString*)productId;
- (UAProduct*)productAtIndex:(int)index;
- (void)updateKeys;

- (void)addProduct:(UAProduct*)product;
- (void)removeProduct:(NSString*)productId;

- (void)setOrderBy:(NSString *)key ascending:(BOOL)ascending;
- (void)sortInventory;

- (void)purchase:(NSString *)productIdentifier;
- (void)updateAll;

+ (NSString*)localizedPrice:(SKProduct*)product;

@end