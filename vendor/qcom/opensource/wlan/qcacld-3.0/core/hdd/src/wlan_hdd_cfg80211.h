/*
 * Copyright (c) 2012-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: wlan_hdd_cfg80211.h
 *
 * WLAN host device driver cfg80211 functions declaration
 */

#if !defined(HDD_CFG80211_H__)
#define HDD_CFG80211_H__

#include <wlan_cfg80211_scan.h>
#include <wlan_cfg80211.h>
#include <wlan_cfg80211_tdls.h>
#include <qca_vendor.h>

struct hdd_context;

/* value for initial part of frames and number of bytes to be compared */
#define GAS_INITIAL_REQ "\x04\x0a"
#define GAS_INITIAL_REQ_SIZE 2

#define GAS_INITIAL_RSP "\x04\x0b"
#define GAS_INITIAL_RSP_SIZE 2

#define GAS_COMEBACK_REQ "\x04\x0c"
#define GAS_COMEBACK_REQ_SIZE 2

#define GAS_COMEBACK_RSP "\x04\x0d"
#define GAS_COMEBACK_RSP_SIZE 2

#define P2P_PUBLIC_ACTION_FRAME "\x04\x09\x50\x6f\x9a\x09"
#define P2P_PUBLIC_ACTION_FRAME_SIZE 6

#define P2P_ACTION_FRAME "\x7f\x50\x6f\x9a\x09"
#define P2P_ACTION_FRAME_SIZE 5

#define SA_QUERY_FRAME_REQ "\x08\x00"
#define SA_QUERY_FRAME_REQ_SIZE 2

#define SA_QUERY_FRAME_RSP "\x08\x01"
#define SA_QUERY_FRAME_RSP_SIZE 2

#define HDD_P2P_WILDCARD_SSID "DIRECT-"
#define HDD_P2P_WILDCARD_SSID_LEN 7

#define WNM_BSS_ACTION_FRAME "\x0a\x07"
#define WNM_BSS_ACTION_FRAME_SIZE 2

#define WNM_NOTIFICATION_FRAME "\x0a\x1a"
#define WNM_NOTIFICATION_FRAME_SIZE 2

#define WPA_OUI_TYPE   "\x00\x50\xf2\x01"
#define BLACKLIST_OUI_TYPE   "\x00\x50\x00\x00"
#define WHITELIST_OUI_TYPE   "\x00\x50\x00\x01"
#define WPA_OUI_TYPE_SIZE  4
#define WMM_OUI_TYPE   "\x00\x50\xf2\x02\x01"
#define WMM_OUI_TYPE_SIZE  5

#define VENDOR1_AP_OUI_TYPE "\x00\xE0\x4C"
#define VENDOR1_AP_OUI_TYPE_SIZE 3

#define WLAN_BSS_MEMBERSHIP_SELECTOR_VHT_PHY 126
#define WLAN_BSS_MEMBERSHIP_SELECTOR_HT_PHY 127
#define BASIC_RATE_MASK   0x80
#define RATE_MASK         0x7f

#ifndef NL80211_AUTHTYPE_FILS_SK
#define NL80211_AUTHTYPE_FILS_SK 5
#endif
#ifndef NL80211_AUTHTYPE_FILS_SK_PFS
#define NL80211_AUTHTYPE_FILS_SK_PFS 6
#endif
#ifndef NL80211_AUTHTYPE_FILS_PK
#define NL80211_AUTHTYPE_FILS_PK 7
#endif
#ifndef WLAN_AKM_SUITE_FILS_SHA256
#define WLAN_AKM_SUITE_FILS_SHA256 0x000FAC0E
#endif
#ifndef WLAN_AKM_SUITE_FILS_SHA384
#define WLAN_AKM_SUITE_FILS_SHA384 0x000FAC0F
#endif
#ifndef WLAN_AKM_SUITE_FT_FILS_SHA256
#define WLAN_AKM_SUITE_FT_FILS_SHA256 0x000FAC10
#endif
#ifndef WLAN_AKM_SUITE_FT_FILS_SHA384
#define WLAN_AKM_SUITE_FT_FILS_SHA384 0x000FAC11
#endif
#ifndef WLAN_AKM_SUITE_DPP_RSN
#define WLAN_AKM_SUITE_DPP_RSN 0x506f9a02
#endif

#define WLAN_AKM_SUITE_OWE 0x000FAC12
#define WLAN_AKM_SUITE_EAP_SHA256 0x000FAC0B
#define WLAN_AKM_SUITE_EAP_SHA384 0x000FAC0C


#ifndef WLAN_AKM_SUITE_SAE
#define WLAN_AKM_SUITE_SAE 0x000FAC08
#endif

#ifndef WLAN_AKM_SUITE_FT_SAE
#define WLAN_AKM_SUITE_FT_SAE 0x000FAC09
#endif

#ifndef WLAN_AKM_SUITE_FT_EAP_SHA_384
#define WLAN_AKM_SUITE_FT_EAP_SHA_384 0x000FAC0D
#endif

#ifdef FEATURE_WLAN_TDLS
#define WLAN_IS_TDLS_SETUP_ACTION(action) \
	((SIR_MAC_TDLS_SETUP_REQ <= action) && \
	(SIR_MAC_TDLS_SETUP_CNF >= action))
#if !defined(TDLS_MGMT_VERSION2)
#define TDLS_MGMT_VERSION2 0
#endif

#endif

#ifdef WLAN_FEATURE_LINK_LAYER_STATS
void wlan_hdd_clear_link_layer_stats(struct hdd_adapter *adapter);
#else
static inline void wlan_hdd_clear_link_layer_stats(struct hdd_adapter *adapter) {}
#endif

#define MAX_CHANNEL (NUM_24GHZ_CHANNELS + NUM_5GHZ_CHANNELS)
#ifndef VENDOR_EDIT
//Chuanye.Xu@PSW.CN.Wifi.Connect.Scan.1234999, 2018/02/22,
//Modify for scan more hidden AP
#define MAX_SCAN_SSID 10
#else /* VENDOR_EDIT */
#define MAX_SCAN_SSID 16
#endif /* VENDOR_EDIT */

#define IS_CHANNEL_VALID(channel) ((channel >= 0 && channel < 15) \
			|| (channel >= 36 && channel <= 184))

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 12, 0)) \
	|| defined(BACKPORTED_CHANNEL_SWITCH_PRESENT)
#define CHANNEL_SWITCH_SUPPORTED
#endif

#if defined(CFG80211_DEL_STA_V2) || (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)) || defined(WITH_BACKPORTS)
#define USE_CFG80211_DEL_STA_V2
#endif

#define OL_TXRX_INVALID_TDLS_PEER_ID 0xff

/**
 * enum eDFS_CAC_STATUS: CAC status
 *
 * @DFS_CAC_NEVER_DONE: CAC never done
 * @DFS_CAC_IN_PROGRESS: CAC is in progress
 * @DFS_CAC_IN_PROGRESS: CAC already done
 */
typedef enum {
	DFS_CAC_NEVER_DONE,
	DFS_CAC_IN_PROGRESS,
	DFS_CAC_ALREADY_DONE,
} eDFS_CAC_STATUS;

#define MAX_REQUEST_ID			0xFFFFFFFF

/* Feature defines */
#define WIFI_FEATURE_INFRA              0x0001  /* Basic infrastructure mode */
#define WIFI_FEATURE_INFRA_5G           0x0002  /* Support for 5 GHz Band */
#define WIFI_FEATURE_HOTSPOT            0x0004  /* Support for GAS/ANQP */
#define WIFI_FEATURE_P2P                0x0008  /* Wifi-Direct */
#define WIFI_FEATURE_SOFT_AP            0x0010  /* Soft AP */
#define WIFI_FEATURE_EXTSCAN            0x0020  /* Extended Scan APIs */
#define WIFI_FEATURE_NAN                0x0040  /* Neighbor Awareness
						 * Networking
						 */
#define WIFI_FEATURE_D2D_RTT		0x0080  /* Device-to-device RTT */
#define WIFI_FEATURE_D2AP_RTT           0x0100  /* Device-to-AP RTT */
#define WIFI_FEATURE_BATCH_SCAN         0x0200  /* Batched Scan (legacy) */
#define WIFI_FEATURE_PNO                0x0400  /* Preferred network offload */
#define WIFI_FEATURE_ADDITIONAL_STA     0x0800  /* Support for two STAs */
#define WIFI_FEATURE_TDLS               0x1000  /* Tunnel directed link
						 * setup
						 */
#define WIFI_FEATURE_TDLS_OFFCHANNEL	0x2000  /* Support for TDLS off
						 * channel
						 */
#define WIFI_FEATURE_EPR                0x4000  /* Enhanced power reporting */
#define WIFI_FEATURE_AP_STA             0x8000  /* Support for AP STA
						 * Concurrency
						 */
#define WIFI_FEATURE_LINK_LAYER_STATS   0x10000  /* Link layer stats */
#define WIFI_FEATURE_LOGGER             0x20000  /* WiFi Logger */
#define WIFI_FEATURE_HAL_EPNO           0x40000  /* WiFi PNO enhanced */
#define WIFI_FEATURE_RSSI_MONITOR       0x80000  /* RSSI Monitor */
#define WIFI_FEATURE_MKEEP_ALIVE        0x100000  /* WiFi mkeep_alive */
#define WIFI_FEATURE_CONFIG_NDO         0x200000  /* ND offload configure */
#define WIFI_FEATURE_TX_TRANSMIT_POWER  0x400000  /* Tx transmit power levels */
#define WIFI_FEATURE_CONTROL_ROAMING    0x800000  /* Enable/Disable roaming */
#define WIFI_FEATURE_IE_WHITELIST       0x1000000 /* Support Probe IE white listing */
#define WIFI_FEATURE_SCAN_RAND          0x2000000 /* Support MAC & Probe Sequence Number randomization */
#define WIFI_FEATURE_SET_LATENCY_MODE   0x40000000 /* Set latency mode */


/* Support Tx Power Limit setting */
#define WIFI_FEATURE_SET_TX_POWER_LIMIT 0x4000000

/* Add more features here */
#define WIFI_TDLS_SUPPORT			BIT(0)
#define WIFI_TDLS_EXTERNAL_CONTROL_SUPPORT	BIT(1)
#define WIIF_TDLS_OFFCHANNEL_SUPPORT		BIT(2)

#define CFG_NON_AGG_RETRY_MAX                  (31)
#define CFG_AGG_RETRY_MAX                      (31)
#define CFG_CTRL_RETRY_MAX                     (31)
#define CFG_PROPAGATION_DELAY_MAX              (63)
#define CFG_PROPAGATION_DELAY_BASE             (64)
#define CFG_AGG_RETRY_MIN                      (5)
#define MGMT_RETRY_MAX                         (31)

struct cfg80211_bss *
wlan_hdd_cfg80211_update_bss_db(struct hdd_adapter *adapter,
				struct csr_roam_info *roam_info);

#define CONNECTIVITY_CHECK_SET_ARP \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_ARP
#define CONNECTIVITY_CHECK_SET_DNS \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_DNS
#define CONNECTIVITY_CHECK_SET_TCP_HANDSHAKE \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_TCP_HANDSHAKE
#define CONNECTIVITY_CHECK_SET_ICMPV4 \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_ICMPV4
#define CONNECTIVITY_CHECK_SET_ICMPV6 \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_ICMPV6
#define CONNECTIVITY_CHECK_SET_TCP_SYN \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_TCP_SYN
#define CONNECTIVITY_CHECK_SET_TCP_SYN_ACK \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_TCP_SYN_ACK
#define CONNECTIVITY_CHECK_SET_TCP_ACK \
	QCA_WLAN_VENDOR_CONNECTIVITY_CHECK_SET_TCP_ACK


int wlan_hdd_cfg80211_pmksa_candidate_notify(struct hdd_adapter *adapter,
					struct csr_roam_info *roam_info,
					int index, bool preauth);

#ifdef FEATURE_WLAN_LFR_METRICS
QDF_STATUS
wlan_hdd_cfg80211_roam_metrics_preauth(struct hdd_adapter *adapter,
				       struct csr_roam_info *roam_info);

QDF_STATUS
wlan_hdd_cfg80211_roam_metrics_preauth_status(struct hdd_adapter *adapter,
					      struct csr_roam_info *roam_info,
					      bool preauth_status);

QDF_STATUS
wlan_hdd_cfg80211_roam_metrics_handover(struct hdd_adapter *adapter,
					struct csr_roam_info *roam_info);
#endif

struct hdd_context *hdd_cfg80211_wiphy_alloc(int priv_size);

int wlan_hdd_cfg80211_tdls_scan(struct wiphy *wiphy,
				struct cfg80211_scan_request *request,
				uint8_t source);

int wlan_hdd_cfg80211_scan(struct wiphy *wiphy,
			   struct cfg80211_scan_request *request);

int wlan_hdd_cfg80211_init(struct device *dev,
			   struct wiphy *wiphy, struct hdd_config *pCfg);

void wlan_hdd_cfg80211_deinit(struct wiphy *wiphy);

void wlan_hdd_update_wiphy(struct hdd_context *hdd_ctx);

void wlan_hdd_update_11n_mode(struct hdd_config *cfg);

int wlan_hdd_cfg80211_register(struct wiphy *wiphy);

/**
 * wlan_hdd_cfg80211_register_frames() - register frame types and callbacks
 * with the PE.
 * @adapter: pointer to adapter
 *
 * This function is used by HDD to register frame types which are interested
 * by supplicant, callbacks for rx frame indication and ack.
 *
 * Return: 0 on success and non zero value on failure
 */
int wlan_hdd_cfg80211_register_frames(struct hdd_adapter *adapter);

void wlan_hdd_cfg80211_deregister_frames(struct hdd_adapter *adapter);

void hdd_reg_notifier(struct wiphy *wiphy,
				 struct regulatory_request *request);

extern void hdd_conn_set_connection_state(struct hdd_adapter *adapter,
					  eConnectionState connState);
QDF_STATUS wlan_hdd_validate_operation_channel(struct hdd_adapter *adapter,
					       int channel);
#ifdef FEATURE_WLAN_TDLS
int wlan_hdd_cfg80211_send_tdls_discover_req(struct wiphy *wiphy,
					     struct net_device *dev, u8 *peer);
#endif

void hdd_select_cbmode(struct hdd_adapter *adapter, uint8_t operationChannel,
		       struct ch_params *ch_params);

/**
 * wlan_hdd_is_ap_supports_immediate_power_save() - to find certain vendor APs
 *				which do not support immediate power-save.
 * @ies: beacon IE of the AP which STA is connecting/connected to
 * @length: beacon IE length only
 *
 * This API takes the IE of connected/connecting AP and determines that
 * whether it has specific vendor OUI. If it finds then it will return false to
 * notify that AP doesn't support immediate power-save.
 *
 * Return: true or false based on findings
 */
bool wlan_hdd_is_ap_supports_immediate_power_save(uint8_t *ies, int length);
void wlan_hdd_del_station(struct hdd_adapter *adapter);

#if defined(USE_CFG80211_DEL_STA_V2)
int wlan_hdd_cfg80211_del_station(struct wiphy *wiphy,
				  struct net_device *dev,
				  struct station_del_parameters *param);
#else
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 16, 0))
int wlan_hdd_cfg80211_del_station(struct wiphy *wiphy,
				  struct net_device *dev,
				  const uint8_t *mac);
#else
int wlan_hdd_cfg80211_del_station(struct wiphy *wiphy,
				  struct net_device *dev,
				  uint8_t *mac);
#endif
#endif /* USE_CFG80211_DEL_STA_V2 */

int wlan_hdd_send_avoid_freq_event(struct hdd_context *hdd_ctx,
				   struct ch_avoid_ind_type *avoid_freq_list);

/**
 * wlan_hdd_send_hang_reason_event() - Send hang reason to the userspace
 * @hdd_ctx: Pointer to hdd context
 * @reason: cds recovery reason
 *
 * Return: 0 on success or failure reason
 */
int wlan_hdd_send_hang_reason_event(struct hdd_context *hdd_ctx,
				    uint32_t reason);

int wlan_hdd_send_avoid_freq_for_dnbs(struct hdd_context *hdd_ctx,
				      uint8_t op_chan);

#ifdef FEATURE_WLAN_EXTSCAN
void wlan_hdd_cfg80211_extscan_callback(void *ctx,
					const uint16_t evType, void *pMsg);
#else
static inline void wlan_hdd_cfg80211_extscan_callback(void *ctx,
					const uint16_t evType, void *pMsg)
{
}
#endif /* FEATURE_WLAN_EXTSCAN */
/**
 * wlan_hdd_rso_cmd_status_cb() - HDD callback to read RSO command status
 * @hdd_handle: opaque handle for the hdd context
 * @rso_status: rso command status
 *
 * This callback function is invoked by firmware to update
 * the RSO(ROAM SCAN OFFLOAD) command status.
 *
 * Return: None
 */
void wlan_hdd_rso_cmd_status_cb(hdd_handle_t hdd_handle,
				struct rso_cmd_status *rso_status);

void hdd_rssi_threshold_breached(void *hddctx,
				 struct rssi_breach_event *data);

/*
 * wlan_hdd_cfg80211_unlink_bss :to inform nl80211
 * interface that BSS might have been lost.
 * @adapter: adapter
 * @bssid: bssid which might have been lost
 * @ssid: SSID
 * @ssid_len: length of the SSID
 *
 * Return: void
 */
void wlan_hdd_cfg80211_unlink_bss(struct hdd_adapter *adapter,
				  tSirMacAddr bssid, uint8_t *ssid,
				  uint8_t ssid_len);

void wlan_hdd_cfg80211_acs_ch_select_evt(struct hdd_adapter *adapter);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
int wlan_hdd_send_roam_auth_event(struct hdd_adapter *adapter, uint8_t *bssid,
		uint8_t *req_rsn_ie, uint32_t req_rsn_length, uint8_t
		*rsp_rsn_ie, uint32_t rsp_rsn_length, struct csr_roam_info
		*roam_info_ptr);
#else
static inline int wlan_hdd_send_roam_auth_event(struct hdd_adapter *adapter,
		uint8_t *bssid, uint8_t *req_rsn_ie, uint32_t req_rsn_length,
		uint8_t *rsp_rsn_ie, uint32_t rsp_rsn_length,
		struct csr_roam_info *roam_info_ptr)
{
	return 0;
}
#endif

int wlan_hdd_cfg80211_update_apies(struct hdd_adapter *adapter);
int wlan_hdd_request_pre_cac(uint8_t channel);
int wlan_hdd_sap_cfg_dfs_override(struct hdd_adapter *adapter);

enum policy_mgr_con_mode wlan_hdd_convert_nl_iftype_to_hdd_type(
					enum nl80211_iftype type);

int wlan_hdd_enable_dfs_chan_scan(struct hdd_context *hdd_ctx,
				  bool enable_dfs_channels);

int wlan_hdd_cfg80211_update_band(struct hdd_context *hdd_ctx,
				  struct wiphy *wiphy,
				  enum band_info eBand);

/**
 * wlan_hdd_try_disconnect() - try disconnnect from previous connection
 * @adapter: Pointer to adapter
 *
 * This function is used to disconnect from previous connection
 *
 * Return: 0 for success, non-zero for failure
 */
int wlan_hdd_try_disconnect(struct hdd_adapter *adapter);

#if defined(CFG80211_DISCONNECTED_V2) || \
(LINUX_VERSION_CODE >= KERNEL_VERSION(4, 2, 0))
static inline void
wlan_hdd_cfg80211_indicate_disconnect(struct net_device *dev,
				      bool locally_generated,
				      int reason,
				      uint8_t *disconnect_ies,
				      uint16_t disconnect_ies_len)
{
	cfg80211_disconnected(dev, reason, disconnect_ies, disconnect_ies_len,
			      locally_generated, GFP_KERNEL);
}
#else
static inline void
wlan_hdd_cfg80211_indicate_disconnect(struct net_device *dev,
				      bool locally_generated,
				      int reason,
				      uint8_t *disconnect_ies,
				      uint16_t disconnect_ies_len)
{
	cfg80211_disconnected(dev, reason, disconnect_ies, disconnect_ies_len,
			      GFP_KERNEL);
}
#endif

/**
 * wlan_hdd_inform_bss_frame() - inform bss details to NL80211
 * @adapter: Pointer to adapter
 * @bss_desc: Pointer to bss descriptor
 *
 * This function is used to inform the BSS details to nl80211 interface.
 *
 * Return: struct cfg80211_bss pointer
 */
struct cfg80211_bss *
wlan_hdd_inform_bss_frame(struct hdd_adapter *adapter,
				     struct bss_description *bss_desc);

/**
 * wlan_hdd_change_hw_mode_for_given_chnl() - change HW mode for given channel
 * @adapter: pointer to adapter
 * @channel: given channel number
 * @reason: reason for HW mode change is needed
 *
 * This API decides and sets hardware mode to DBS based on given channel.
 * For example, some of the platforms require DBS hardware mode to operate
 * in 2.4G channel
 *
 * Return: 0 for success and non-zero for failure
 */
int wlan_hdd_change_hw_mode_for_given_chnl(struct hdd_adapter *adapter,
				uint8_t channel,
				enum policy_mgr_conn_update_reason reason);

/**
 * hdd_rate_info_bw: an HDD internal rate bandwidth representation
 * @HDD_RATE_BW_5: 5MHz
 * @HDD_RATE_BW_10: 10MHz
 * @HDD_RATE_BW_20: 20MHz
 * @HDD_RATE_BW_40: 40MHz
 * @HDD_RATE_BW_80: 80MHz
 * @HDD_RATE_BW_160: 160 MHz
 */
enum hdd_rate_info_bw {
	HDD_RATE_BW_5,
	HDD_RATE_BW_10,
	HDD_RATE_BW_20,
	HDD_RATE_BW_40,
	HDD_RATE_BW_80,
	HDD_RATE_BW_160,
};

/**
 * hdd_set_rate_bw(): Set the bandwidth for the given rate_info
 * @info: The rate info for which the bandwidth should be set
 * @hdd_bw: HDD representation of a rate info bandwidth
 */
void hdd_set_rate_bw(struct rate_info *info, enum hdd_rate_info_bw hdd_bw);

/**
 * hdd_lost_link_info_cb() - callback function to get lost link information
 * @hdd_handle: Opaque handle for the HDD context
 * @lost_link_info: lost link information
 *
 * Return: none
 */
void hdd_lost_link_info_cb(hdd_handle_t hdd_handle,
			   struct sir_lost_link_info *lost_link_info);
/*
 * hdd_get_sap_operating_band:  Get current operating channel
 * for sap.
 * @hdd_ctx: hdd context
 *
 * Return : Corresponding band for SAP operating channel
 */
uint8_t hdd_get_sap_operating_band(struct hdd_context *hdd_ctx);

/**
 * wlan_hdd_try_disconnect() - try disconnnect from previous connection
 * @adapter: Pointer to adapter
 *
 * This function is used to disconnect from previous connection
 *
 * Return: 0 for success, non-zero for failure
 */
int wlan_hdd_try_disconnect(struct hdd_adapter *adapter);

/**
 * wlan_hdd_disconnect() - hdd disconnect api
 * @adapter: Pointer to adapter
 * @reason: Disconnect reason code
 *
 * This function is used to issue a disconnect request to SME
 *
 * Return: 0 for success, non-zero for failure
 */
int wlan_hdd_disconnect(struct hdd_adapter *adapter, u16 reason);

/**
 * hdd_update_cca_info_cb() - stores congestion value in station context
 * @hdd_handle: HDD handle
 * @congestion: congestion
 * @vdev_id: vdev id
 *
 * Return: None
 */
void hdd_update_cca_info_cb(hdd_handle_t hdd_handle, uint32_t congestion,
			    uint32_t vdev_id);

/**
 * wlan_hdd_get_adjacent_chan(): Gets next/previous channel
 * to the channel passed.
 * @chan: Channel
 * @upper: If "true" then next channel is returned or else
 * previous channel is returned.
 *
 * This function returns the next/previous adjacent-channel to
 * the channel passed. If "upper = true" then next channel is
 * returned else previous is returned.
 */
int wlan_hdd_get_adjacent_chan(uint8_t chan, bool upper);

/**
 * wlan_hdd_merge_avoid_freqs(): Merge two tHddAvoidFreqList
 * @destFreqList: Destination list in which merged frequency
 * list will be available.
 * @srcFreqList: Source frequency list.
 *
 * Merges two avoid_frequency lists
 */
int wlan_hdd_merge_avoid_freqs(struct ch_avoid_ind_type *destFreqList,
		struct ch_avoid_ind_type *srcFreqList);


/**
 * hdd_bt_activity_cb() - callback function to receive bt activity
 * @hdd_handle: Opaque handle to the HDD context
 * @bt_activity: specifies the kind of bt activity
 *
 * Return: none
 */
void hdd_bt_activity_cb(hdd_handle_t hdd_handle, uint32_t bt_activity);

#ifdef WLAN_FEATURE_GTK_OFFLOAD
/**
 * wlan_hdd_save_gtk_offload_params() - Save gtk offload parameters in STA
 *                                      context for offload operations.
 * @adapter: Adapter context
 * @kck_ptr: KCK buffer pointer
 * @kek_ptr: KEK buffer pointer
 * @kek_len: KEK length
 * @replay_ctr: Pointer to 64 bit long replay counter
 * @big_endian: true if replay_ctr is in big endian format
 *
 * Return: None
 */
void wlan_hdd_save_gtk_offload_params(struct hdd_adapter *adapter,
				      uint8_t *kck_ptr, uint8_t  kck_len,
				      uint8_t *kek_ptr, uint32_t kek_len,
				      uint8_t *replay_ctr, bool big_endian);
#else
void wlan_hdd_save_gtk_offload_params(struct hdd_adapter *adapter,
				      uint8_t *kck_ptr, uint8_t kck_len,
				      uint8_t *kek_ptr, uint32_t kek_len,
				      uint8_t *replay_ctr, bool big_endian)
{}
#endif

/*
 * wlan_hdd_send_mode_change_event() - API to send hw mode change event to
 * userspace
 *
 * Return : 0 on success and errno on failure
 */
int wlan_hdd_send_mode_change_event(void);

/**
 * wlan_hdd_restore_channels() - Restore the channels which were cached
 * and disabled in wlan_hdd_disable_channels api.
 * @hdd_ctx: Pointer to the HDD context
 * @notify_sap_event: Indicates if SAP event needs to be notified
 *
 * Return: 0 on success, Error code on failure
 */
int wlan_hdd_restore_channels(struct hdd_context *hdd_ctx,
			      bool notify_sap_event);

/**
 * hdd_store_sar_config() - Store SAR config in HDD context
 * @hdd_ctx: The HDD context
 * @sar_limit_cmd: The sar_limit_cmd_params struct to save
 *
 * After SSR, the SAR configuration is lost. As SSR is hidden from
 * userland, this command will not come from userspace after a SSR. To
 * restore this configuration, save this in hdd context and restore
 * after re-init.
 *
 * Return: None
 */
void hdd_store_sar_config(struct hdd_context *hdd_ctx,
			  struct sar_limit_cmd_params *sar_limit_cmd);

/**
 * hdd_free_sar_config() - Free the resources allocated while storing SAR config
 * @hdd_ctx: HDD context
 *
 * The driver stores the SAR config values in HDD context so that it can be
 * restored in the case SSR is invoked. Free those resources.
 *
 * Return: None
 */
void wlan_hdd_free_sar_config(struct hdd_context *hdd_ctx);
#endif
