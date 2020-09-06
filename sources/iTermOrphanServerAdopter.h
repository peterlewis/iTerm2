//
//  iTermOrphanServerAdopter.h
//  iTerm2
//
//  Created by George Nachman on 6/7/15.
//
//

#import <Foundation/Foundation.h>
#import "iTermMultiServerProtocol.h"
#import "PTYTask.h"

@class PTYSession;
@class iTermMultiServerConnection;

@protocol iTermOrphanServerAdopterDelegate<NSObject>
- (void)orphanServerAdopterOpenSessionForConnection:(iTermGeneralServerConnection)connection
                                           inWindow:(id)window
                                         completion:(void (^)(PTYSession *))completion;
@end

@interface iTermOrphanServerAdopter : NSObject

@property(nonatomic, readonly) BOOL haveOrphanServers;
@property(nonatomic, weak) id<iTermOrphanServerAdopterDelegate> delegate;

+ (instancetype)sharedInstance;
- (void)openWindowWithOrphansWithCompletion:(void (^)(void))completion;
- (void)removePath:(NSString *)path;

@end
