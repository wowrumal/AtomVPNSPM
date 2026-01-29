platform :ios, '16.1'

install! 'cocoapods', 
    :integrate_targets => false,
    :skip_pods_project_generation => true,
    :clean => true,
    :parallel_pod_downloads => true,
    :parallel_pod_download_thread_pool_size => 40

target 'DummyTarget' do
    use_frameworks!

    pod 'AtomSDKBySecure'
    pod 'AtomSDKTunnel' 
end