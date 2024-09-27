import { useCallback, useEffect, useRef, useState } from 'react';
import { ZoomSDK } from '../native/ZoomSDK';
const DEFAULT_CONFIG = {
  domain: 'zoom.us',
  enableLog: true,
  logSize: 5
};
export function useSDKHandler(config = {}) {
  const SDKHandler = useRef(new ZoomSDK());
  const [isInited, setIsInited] = useState(false);
  useEffect(() => {
    if (!isInited) {
      SDKHandler.current.initSDK({
        ...DEFAULT_CONFIG,
        ...config
      });
      setIsInited(true);
    }
  }, [config, isInited]);
  const isInitialized = useCallback(() => {
    return SDKHandler.current.isInitialized();
  }, []);
  const updateMeetingSetting = useCallback(config => {
    SDKHandler.current.updateMeetingSetting(config);
  }, []);
  const joinMeeting = useCallback(config => {
    return SDKHandler.current.joinMeeting(config);
  }, []);
  const startMeeting = useCallback(config => {
    return SDKHandler.current.startMeeting(config);
  }, []);
  return {
    isInitialized,
    updateMeetingSetting,
    joinMeeting,
    startMeeting
  };
}
//# sourceMappingURL=useSDKHandler.js.map