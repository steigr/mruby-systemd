class Systemd
	class << self
		def notify *args
			args[0].each do |k,v|
				state = "READY=#{v}" if k == :ready
				unset_environment = v if k == :unset_environment
			end if args[0]

			unset_environment ||= 1
			state             ||= "READY=1"

			unset_environment = 1 if unset_environment == true
			unset_environment = 0 if unset_environment == false

			CSystemd.notify(unset_environment,state)
		end
	end
end