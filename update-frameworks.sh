#!/bin/bash

set -e

PROJECT_DIR="$(dirname "${BASH_SOURCE[0]}")"
FRAMEWORKS_DIR="$PROJECT_DIR/Frameworks"
PODS_DIR="$PROJECT_DIR/Pods"

echo "==> Running pod install..."
cd "$PROJECT_DIR"
pod install

echo "==> Creating Frameworks directory..."
mkdir -p "$FRAMEWORKS_DIR"

echo "==> Copying xcframeworks from Pods to Frameworks..."

# AtomSDKBySecure
cp -R "$PODS_DIR/AtomSDKBySecure/AtomSDK.xcframework" "$FRAMEWORKS_DIR/"

# AtomCore
cp -R "$PODS_DIR/AtomCore/AtomCore.xcframework" "$FRAMEWORKS_DIR/"

# AtomSDKTunnel
cp -R "$PODS_DIR/AtomSDKTunnel/AtomSDKTunnel.xcframework" "$FRAMEWORKS_DIR/"
cp -R "$PODS_DIR/AtomSDKTunnel/AtomOVPNTunnel.xcframework" "$FRAMEWORKS_DIR/"
cp -R "$PODS_DIR/AtomSDKTunnel/OpenVPNClient.xcframework" "$FRAMEWORKS_DIR/"
cp -R "$PODS_DIR/AtomSDKTunnel/mbedTLS.xcframework" "$FRAMEWORKS_DIR/"
cp -R "$PODS_DIR/AtomSDKTunnel/LZ4.xcframework" "$FRAMEWORKS_DIR/"

echo "==> Done! Frameworks copied to $FRAMEWORKS_DIR"