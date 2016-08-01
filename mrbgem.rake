MRuby::Gem::Specification.new('systemd') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Mathias Kaufmann <steigr@me.com>'
  spec.linker.libraries << 'systemd'
end
