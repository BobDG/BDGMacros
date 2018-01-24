Pod::Spec.new do |s|
  s.name           = 'BDGMacros'
  s.version        = '0.0.22'
  s.summary        = 'xCode Macros'
  s.license 	   = 'MIT'
  s.description    = 'Really useful macros to use in every xCode project, such as isPad, conversions, suppress warnings, singleton, dlog, documentsfolder'
  s.homepage       = 'https://github.com/BobDG/BDGMacros'
  s.authors        = {'Bob de Graaf' => 'graafict@gmail.com'}
  s.source         = { :git => 'https://github.com/BobDG/BDGMacros.git', :tag => s.version.to_s }
  s.source_files   = '*.{h,m}'  
  s.module_name    = 'BDGMacros' 
  s.platform       = :ios
  s.requires_arc   = true
  s.ios.deployment_target = '8.0'
end
