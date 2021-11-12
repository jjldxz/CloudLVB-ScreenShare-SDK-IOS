//
//  CLS_UploaderManager.h
//  CLS_ShareSDK
//
//  Created by Fox Doggy on 2021/10/20.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

#define notification_beigin_indentify       @"CLS_SCREENSHARE_BEGIN_NOTIFICATIONID"
#define notification_stop_indentify         @"CLS_SCREENSHARE_STOP_NOTIFICATIONID"
#define notification_need_close_indentify   @"CLS_SCREENSHARE_NEED_CLOSE_NOTIFICATIONID"

@interface CLS_UploaderManager : NSObject

+ (instancetype)sharedInstance NS_SWIFT_NAME(shareManager());

- (void)joinRTCWithUserId:(NSNumber *)user_id
                AuthToken:(NSString *)token
                   AppKey:(NSString *)appKey
               RoomNumber:(NSNumber *)number
         CompletedHandler:(void (^)(BOOL success, NSError *_Nullable error))handler;

- (void)startBroadcast;

- (void)sendVideoBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)sendAudioAppBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)sendAudioMicBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)stopBroadcast;

@end

NS_ASSUME_NONNULL_END
