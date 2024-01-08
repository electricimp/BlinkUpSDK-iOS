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
            url: "https://github.com/electricimp/BlinkUpSDK-iOS/releases/download/20.2.0/blinkup_sdk_ios_v20.2.0.xcframework.zip",
            checksum: "65f4fded8ddef3026bd8fe4a8fb79a02c53b6521de9b43dd6b245ce491df26c4"),
    ]
)

