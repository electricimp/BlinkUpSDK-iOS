# The Electric Imp BlinkUp SDK for iOS #

This repo contains the Electric Imp BlinkUp™ SDK for iOS as it is made available to Electric Imp customers. It mirrors the downloadable files hosted by the [Dev Center](https://developer.electricimp.com/manufacturing/sdkdocs), but in a form that allows developers to add the SDK to their iOS app projects as a Swift Package.

**Note** The SDK was previously made available as a Git sub-module. This mode is now deprecated and will shortly be removed. We strongly recommend customers add the SDK to their iOS app projects using Xcode’s Swift Package Manager as outlined below.

## Swift Package Installation ##

1. Open your project in Xcode.
1. Go to **File > Swift Packages > Add Package Dependency...** and add this repo as a dependency.
1. Apply your preferred dependency rules.
1. Ensure that your targets `Build Settings` has `-ObjC` set for `Other Linker Flags`

## Moving to Swift Package Manager from a manual install or sub-module ##

1. If you have previously had the SDK installed via sub-module, you can remove the sub-module reference in your git repository.
1. The `BlinkUp.embeddedframework` can be deleted from your Xcode Project.
1. If you wish, you can remove your targets `Build Settings` for the `Framework Search Paths` that references the old framework.

## BlinkUp SDK Documentation ##

To learn how to use the BlinkUp SDK in your app, please see [the SDK documentation](./docs/html/index.html) (HTML).

## Release Notes and Known Issues ##

Please see the [Dev Center SDK page](https://developer.electricimp.com/manufacturing/sdkdocs), or the [SDK documentation in this repo](./docs/html/index.html).

## Pull Requests ##

The BlinkUp SDK repo is considered solely for consumption by a customer’s project. We will not be accepting pull requests made to this repo. If you have support or related questions concerning the SDK, please submit them through your customer account’s [Electric Imp Support access](https://support.electricimp.com/).

## Sub-module Installation ##

**Important** This mode is deprecated and will shortly be removed.

To install the SDK as a sub-module, navigate to your project repo directory and then enter the following command:

```
git submodule add https://github.com/electricimp/BlinkUpSDK-iOS.git
```

This will add the SDK repo as a sub-module referenced in the file `.gitmodules`, which will be added if it is not yet present. You can now push your local repo to its origin:

```
git push origin <working_branch>
```

To update the sub-module contents at any time, eg. in a build script, call:

```
git submodule update --remote
```

---

The BlinkUp SDK is copyright &copy; 2024, KORE Wireless.
