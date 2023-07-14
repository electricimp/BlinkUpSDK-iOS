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
            url: "https://github.com/electricimp/BlinkUpSDK-iOS/releases/download/20.1.1/blinkup_sdk_ios_v20.1.1.xcframework.zip",
            checksum: "7487b4c0dda1ce5b6092995f8a8e09631220d7e119bddc50f31eeb2197a085e4"),
    ]
)

