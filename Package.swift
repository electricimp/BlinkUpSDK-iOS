// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "BlinkUp",
    products: [
        .library(
            name: "BlinkUp",
            targets: ["BlinkUp"]),
    ],
    targets: [
        .binaryTarget(
            name: "BlinkUp",
            url: "https://github.com/electricimp/BlinkUpSDK-iOS/releases/download/20.0.2/blinkup_sdk_ios_v20.0.2.xcframework.zip",
            checksum: "f7b0d66e0c5c340ca9f58968536ce7893e3d3f4cd2ccfa31aff431b87f3a6f46"),
    ]
)

