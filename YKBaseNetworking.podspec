#
#  Be sure to run `pod spec lint YKBaseNetworking.podspec.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "YKBaseNetworking"
  spec.version      = "0.0.3"
  spec.summary      = "An IOS network development tool based on AFNetworking"
  spec.description  = "An IOS network development tool based on AF networking."
  spec.homepage     = "https://github.com/yikevideo/YKBaseNetworking.git"
  spec.license      = "MIT"
  # spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.author             = { "ykvideo" => "yikevideo@163.com" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/yikevideo/YKBaseNetworking.git", :tag => "#{spec.version}" }
  # spec.vendored_frameworks = "*.{framework}"
  # source_files      = "YKBaseNetworking/*.{framework}"
  s.vendored_frameworks = 'YKBaseNetworking/YKBaseNetworking.framework'
  spec.dependency "AFNetworking", "~> 3.0"

end
