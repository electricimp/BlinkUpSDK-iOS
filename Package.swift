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
            checksum: "3638e573a6377e1ce341e4b93c200f749e15021c9598f7ce320a1ef761f75ab9"),
    ]
)

