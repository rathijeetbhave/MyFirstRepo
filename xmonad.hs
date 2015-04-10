import XMonad 
import System.Exit
import XMonad.Util.EZConfig 
import XMonad.Hooks.DynamicLog 
import XMonad.Hooks.ManageDocks 
import XMonad.Util.Run 
import System.IO
import Graphics.X11.ExtraTypes.XF86
import XMonad.Layout.NoBorders
import XMonad.Layout.SimpleFloat
import XMonad.Layout.PerWorkspace
import qualified XMonad.StackSet as W
import Control.Monad (liftM2)
import XMonad.Layout.LimitWindows
import XMonad.Config.Gnome


--Define amount and names of workspaces
myWorkspaces = ["1:main","2:web","3:media","4:code","5:whatever"]

myManageHook = composeAll 
	[ className =? "MPlayer" --> viewShift "3:media"  
	, className =? "Firefox" --> viewShift "2:web" 
	] 
	where viewShift = doF . liftM2 (.) W.greedyView W.shift

main = do 
    xmproc <- spawnPipe "xmobar"
    xmonad $ gnomeConfig 
	{
	modMask = mod1Mask
	, terminal="bash"
	, workspaces = myWorkspaces
	, manageHook = manageDocks <+> myManageHook <+> manageHook defaultConfig 
	, layoutHook = avoidStruts $ smartBorders $ layoutHook defaultConfig 
	, logHook = dynamicLogWithPP xmobarPP
		{ ppOutput = hPutStrLn xmproc 
		, ppTitle = xmobarColor "blue" "" . shorten 50 
		, ppLayout = const "" -- to disable the layout info on xmobar 
		}
	}`additionalKeys` 
	[
	(( mod1Mask, xK_f), spawn "firefox") -- to open firefox 
	,(( mod1Mask .|. shiftMask, xK_F4), spawn "sudo shutdown -h now") -- window key + Shift + F4 to shutdown system 
	,(( mod1Mask, xK_c), kill) -- to kill applications 
	,(( controlMask, xK_KP_Add), sendMessage Expand) -- Ctrl + the plus (+) button to expand the master pane 
	,(( controlMask, xK_KP_Subtract), sendMessage Shrink) -- Ctrl + the plus (+) button to expand the master pane 
	,((mod1Mask, xK_b), spawn "xbacklight -20")
	,((mod1Mask .|. shiftMask, xK_b), spawn "xbacklight +5")
        ,((mod1Mask , xK_t), sendMessage ToggleStruts)-- Toggle Struts
	,((mod1Mask .|. shiftMask , xK_c), return ()) -- return() means to do nothing  
	,((mod1Mask .|. shiftMask , xK_q), io exitSuccess) -- return() means to do nothing  
	
	-- Audio Lower Volume
	,((0,xF86XK_AudioLowerVolume), spawn "amixer -D pulse sset Master 7%-")

	-- Audio Raise Volume
	,((0,xF86XK_AudioRaiseVolume), spawn "amixer -D pulse sset Master 7%+")

	-- Audio Mute
	,((0,xF86XK_AudioMute), spawn "amixer -q -D pulse sset Master toggle")
	]
	
