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
            url: "https://github.com/electricimp/BlinkUpSDK-iOS/releases/download/v20.1.0/blinkup_sdk_ios_v20.1.0.xcframework.zip",
            checksum: "c8bb77e4f7837f24860e5c109eb6de22a4be8c334df91b18c850d7173f60ca55"),
    ]
)

