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
            checksum: "d1383eb2babd0132b679e4cbce768cefbd16159357067ff81c01929410e451e8"),
    ]
)

