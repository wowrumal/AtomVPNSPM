// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "AtomSDKSPM",
    platforms: [
        .iOS(.v12),
        .macOS(.v10_15),
        .tvOS(.v17)
    ],
    products: [
        .library(
            name: "AtomSDK",
            targets: ["AtomSDK", "AtomCore"]
        ),
        .library(
            name: "AtomSDKTunnel",
            targets: ["AtomSDKTunnel", "AtomOVPNTunnel", "OpenVPNClient", "mbedTLS", "LZ4"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "AtomSDK",
            path: "Frameworks/AtomSDK.xcframework"
        ),
        .binaryTarget(
            name: "AtomCore",
            path: "Frameworks/AtomCore.xcframework"
        ),
        .binaryTarget(
            name: "AtomSDKTunnel",
            path: "Frameworks/AtomSDKTunnel.xcframework"
        ),
        .binaryTarget(
            name: "AtomOVPNTunnel",
            path: "Frameworks/AtomOVPNTunnel.xcframework"
        ),
        .binaryTarget(
            name: "OpenVPNClient",
            path: "Frameworks/OpenVPNClient.xcframework"
        ),
        .binaryTarget(
            name: "mbedTLS",
            path: "Frameworks/mbedTLS.xcframework"
        ),
        .binaryTarget(
            name: "LZ4",
            path: "Frameworks/LZ4.xcframework"
        ),
    ]
)

