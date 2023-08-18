import subprocess

def Settings(** kwargs):
    wx_config_output = subprocess.check_output(['./build/vendor/wxWidgets/wx-config', '--cxxflags', '--libs'], text=True)
    wx_config_flags = wx_config_output.strip().split()
    return {
            'flags': [
                '-I./include',
                *wx_config_flags,
                ],
            }
