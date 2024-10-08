//
//  MobileRTCZpnsHelper.h
//  MobileRTC
//
//  Created by Zoom on 2024/7/16.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileRTCConstants.h>
#import <MobileRTCInMeetingDeviceInfo.h>
#import <MobileRTCPresenceHelper.h>


@protocol MobileRTCNotificationServiceHelperDelegate <NSObject>
@optional

/*!
 @brief Callback event that the device for users to attend the meeting has changed.
 @param deviceList A list of meeting info with active meetings.
 */
- (void)onMeetingDeviceListChanged:(NSArray<MobileRTCInMeetingDeviceInfo*>*_Nullable)deviceList;

/*!
 @brief Transfer meeting status changed callback.
 @param bSuccess The result of transfer meeting.
 */
- (void)onTransferMeetingStatus:(BOOL)bSuccess;

@end

@interface MobileRTCNotificationServiceHelper : NSObject
/*!
 Set the delegate of access token service.
 */
@property (assign, nonatomic) id<MobileRTCNotificationServiceHelperDelegate> _Nullable delegate;

/*!
 @brief Determine whether the transfer meeting feature is enabled.
 */
- (BOOL)isTransferMeetingEnabled;

/*!
 @brief Determine whether the presence feature is enabled.
 */
- (BOOL)isPresenceFeatureEnabled;
/*!
 @brief Try to transfer meeting to current device.
 @param index Specifies the index, see [MobileRTCInMeetingDeviceInfo].
 @return If the function succeeds, the return value is MobileRTCSDKError_Success.
 Otherwise failed. To get extended error information, see [MobileRTCSDKError] enum.
 */
- (MobileRTCSDKError)transferMeeting:(NSInteger)index;


/*!
 @brief Get presence interface helper.
 @return If the function succeeds, the return value is a instance of MobileRTCPresenceHelper, Otherwise, the function returns NULL.
 */
- (MobileRTCPresenceHelper *_Nullable)getPresenceHelper;

@end

