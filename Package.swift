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
            url: "https://github.com/electricimp/BlinkUpSDK-iOS/releases/download/20.0.1/blinkup_sdk_ios_v20.0.1.xcframework.zip",
            checksum: "768f0ab8c090222c2733ecaeeea354f27bcd512e6dfc97df97932374140e18f6"),
    ]
)

