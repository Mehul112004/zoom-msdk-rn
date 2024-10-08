//
//  MobileRTCMeetingService+RawArchiving.h
//  MobileRTC
//
//  Created by Zoom Video Communications on 2024/7/25.
//  Copyright © 2024 Zoom Video Communications, Inc. All rights reserved.
//

#import <MobileRTC.h>

@interface MobileRTCMeetingService (RawArchiving)

/**
 * @brief Start raw archiving and get raw data receive previlege.
 * @return YES if start raw archiving succeeds. Otherwise failed.
 */
- (BOOL)startRawArchiving;

/**
 * @brief Stop raw archiving and revoke rawdata receive previlege.
 * @return YES if stop raw archiving succeeds. Otherwise failed.
 */
- (BOOL)stopRawArchiving;

@end

