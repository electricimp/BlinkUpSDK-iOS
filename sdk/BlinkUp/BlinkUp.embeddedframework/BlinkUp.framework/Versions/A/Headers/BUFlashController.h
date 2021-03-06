//
//  BUFlashController.h
//  BlinkUp
//
//  Created by Brett Park on 2014-12-10.
//  Copyright © 2020 Twilio, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BUDevicePoller;
@class BUWifiConfig;
@class BUWPSConfig;
@class BUNetworkConfig;
@class BUConfigId;
@class BUFlashStringParameters;

/*!
 *  @brief  Block that is called when the presenting screen resumes control
 *
 *  @param willRespond   If true, it is expected that the ImpeeDidConnectBlock
 *            will be called. If false, the ImpeeDidConnectBlock will not be called
 *  @param devicePoller      Nil if willRespond is true, otherwise it contains the
 *    device poller that will retrieve the device data from the server. It does
 *    not automatically start the data retrieval.
 *  @param error         Nil if no error or contains the error
 */
typedef void (^FlashResignActiveBlock)(BOOL willRespond, BUDevicePoller *_Nullable devicePoller, NSError *_Nullable error);

/*!
 *  Perform a BlinkUp using screen flashes
 *
 *  The flash controller is used to relay the BlinkUp information to the
 *  device using screen flashes.
 */
@interface BUFlashController : NSObject

/*!
 *  @brief  Perform a BlinkUp
 *
 *   If using Swift and want enumerated results, please use the Swift extension method
 *
 *  @param networkConfig   The WifiConfig, WpsConfig, or ClearConfig that is to
 *    be performed.
 *  @param configId        The single use configId for this flashing session. This
 *                         can be nil in the case of clearing a device
 *  @param animated        Should the presentation be animated
 *  @param resignActive    Block that is executed when the BlinkUp screen is
 *        dismissed and control is returned to the presenting screen
 */
- (void)presentFlashWithNetworkConfig:(nonnull BUNetworkConfig *)networkConfig
  configId:(nullable BUConfigId *)configId
  animated:(BOOL)animated
  resignActive:(nullable FlashResignActiveBlock)resignActive;

#pragma mark - Properties

/*!
 *  @brief Seconds before BlinkUp begins
 *
 *   Before the BlinkUp flashes occur there is a countdown to allow the user to
 *   prepare the device. The preFlashCountdownTime is the number of seconds that
 *   the countdown occurs for. The default is 3 seconds. This property cannot be
 *   set lower than 3 seconds, and not more than 10.
 */
@property (nonatomic, assign) NSInteger preFlashCountdownTime;


/*!
 *  @brief  Pre-flash interstitial (optional)
 *
 *  Suggested iPhone image size of 280x380 pixels \@1x and 560x760 pixels \@2x (retina)
 *  The image will be resized to AspectFit the area up to its instrinsic size
 *  If you are supporting iOS 8+ you can utilize Image Asset Size Classes to
 *  automatically choose an appropriate image for the size class
 */
@property (nonatomic, strong, nullable) UIImage *interstitialImage;

/*!
 *  @brief  Brightness of the screen during the flash
 *
 *  A value from 0 ... 1 indicating brightness of the screen from 0 (darkest)
 *  to 1 (brightest). If your sensor is running hot, you can lower this number
 *
 *  Default value is 0.8
 */
@property (nonatomic, assign) float screenBrightness;

/*!
 *  @brief List of strings that can be customized
 *
 *    On occasion it may be useful to change or append to it additional information about the
 *    state of the application for the user (such as the device they are about to BlinkUp,
 *    or their username). By adding objects into the various stringParams arrays it is possible
 *    to inject dynamic content using standard stringWithFormat notation in the localized file string
 *    for example "Now connecting device %\@" (remove the backslash if reading source)
 *
 *    Most of these strings can also be modified in the localization file
 */
@property (nonatomic, readonly, strong, nonnull) BUFlashStringParameters *stringParams;

/*!
 *  If set to true, the status bar will be hidden after the Flash completes
 *  This method is now deprecated and does not affect the status bar (as of 19.6.0). 
 *  Please use prefersStatusBarHidden on your view controller.
 */
@property (nonatomic, assign) BOOL hideStatusBarAfterFlash;

/*!
 *  During the BlinkUp process the AVAudioSession category is set to AVAudioSessionCategoryAmbient
 * If your application already sets the AVAudioSession category, setting this propery
 * to true will disable the AVAudioSession category change and activation.
 */
@property (nonatomic, assign) BOOL disableAudioSessionChange;

/*!
 *  When set to true, the phone will vibrate (if capable) once the flash has completed
 *  Defaults to false
 */
@property (nonatomic, assign) BOOL vibrateOnFlashComplete;

/*!
 *  When set to true, the LED torch (if cabable) will be turned on briefly once the flash process is complete.
 *  Defaults to false
 */
@property (nonatomic, assign) BOOL torchOnFlashComplete;

/*!
   On occasion a special feature needs to be set. The special features are set by featureName value.
   In order to use these options, the feature must be unlocked using supply the feature key to the
   BUSDKFeature class.

   @param featureName String representing the feature to unlock
   @param value      The value of the feature. This must be of the proper type.
                     A value of nil will unset the value
 */

/*!
 *  @brief Set an extra feature
 *
 *  On occasion an extra feature needs to be set. The special feature is set by featureName and value.
 *  In order to use these options, the feature must first be enabled by the <BUSDK> class.
 *
 *  @param featureName  String representing the feature to set
 *  @param object       The value of the feature. This must be of the proper type.
 *                      A value of nil will unset the value
 *  @param error    A non-nil value if an issue was encountered while setting the feature
 */
- (BOOL)setFeature:(nonnull NSString *)featureName object:(nullable NSObject *)object error:(NSError *_Nullable *_Nullable)error;

/*!
 *  @brief Advanced features that are active
 *
 *  The features dictionaries holds the current list advanced features that are active
 */
@property (copy, nonatomic, nonnull) NSDictionary *features;

@end
