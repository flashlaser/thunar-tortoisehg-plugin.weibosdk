/**
*  @brief Micro blog request option.
*  @file  wbRequest.cpp
*  @author loach 
*  @Email < loachmr@sina.com >
*
* Copyright (C) 1996-2010 SINA Corporation, All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*/
#include "wbRequest.h"
#include <stdlib.h>
#include <string.h>



#define MALLOC(obj) \
	{\
	    size = sizeof(struct obj);\
		pnewstruct = malloc( size );\
		memset(pnewstruct,0,sizeof(obj));\
	}

//
void* Weibo_senddata_create(int type , const void* senddata)
{
	void* pnewstruct = 0;
	int   size = 0;


	if( !senddata )
		return 0;

	switch(type)
	{
	case WEIBO_OPTION(BASE):
		MALLOC( t_wb_oauth ) ;
		break;

		//--------------------------------------获取下行数据集(timeline)

	case WEIBO_OPTION(GETSTATUSES_PUBLIC_TIMELINE):
		MALLOC( t_wb_get_statuses_public_timeline ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_FRIENDS_TIMELINE):
		MALLOC( t_wb_get_statuses_friends_timeline ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_USE_TIMELINE):
		MALLOC( t_wb_get_statuses_user_timeline ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_MENTIONS):
		MALLOC( t_wb_get_statuses_mentions ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_COMMENTS_TIMELINE):
		MALLOC( t_wb_get_statuses_comments_timeline ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_COMMENTS_BYME):
		MALLOC( t_wb_get_statuses_comments_byme ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_COMMENTS_TOME):
		MALLOC( t_wb_get_statuses_comments_tome ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_COMMENTS_LIST):
		MALLOC( t_wb_get_statuses_comments_list ) ;
		break;

	case WEIBO_OPTION(GETSTATUSES_COMMENTS_COUNTS):
		MALLOC( t_wb_get_statuses_counts  );
		break;

	case WEIBO_OPTION(GETSTATUSES_UNREAD):
		MALLOC( t_wb_get_statuses_unread  );
		break;

	case WEIBO_OPTION(PUTSTATUSES_RESET_COUNT):
		MALLOC( t_wb_get_statuses_reset_count  );
		break;

		//--------------------------------------微博访问
	case WEIBO_OPTION(GETSTATUSES_SHOW):
		MALLOC( t_wb_get_statuses_show );
		break;

	case WEIBO_OPTION(GOTOSTATUSES_ID):
		MALLOC( t_wb_goto_user_status_id );
		break;

	case WEIBO_OPTION(PUTSTATUSES_UPDATE):
		MALLOC( t_wb_put_statuses_update );
		break;

	case WEIBO_OPTION(PUTSTATUSES_UPLOAD):
		MALLOC( t_wb_put_statuses_upload );
		break;

    case WEIBO_OPTION(PUTSTATUSES_DESTROY):
		MALLOC( t_wb_put_statuses_destroy );
		break;

	case WEIBO_OPTION(PUTSTATUSES_REPOST):
		MALLOC( t_wb_put_statuses_repost );
		break;

	case WEIBO_OPTION(PUTSTATUSES_COMMENT):
		MALLOC( t_wb_put_statuses_comment );
		break;

	case WEIBO_OPTION(PUTSTATUSES_COMMENT_DESTROY):
		MALLOC(  t_wb_put_statuses_comment_destroy );
		break;

	case WEIBO_OPTION(PUTSTATUSES_REPLY):
		MALLOC(  t_wb_put_statuses_reply  );
		break;

		//---------------------------------------------用户
	case WEIBO_OPTION(GETUSER_INFO):
		MALLOC( t_wb_get_users_show ) ;
		break;


	case WEIBO_OPTION(GETFRINDS_LIST):
		MALLOC(  t_wb_get_statuses_friends );
		break;

	case WEIBO_OPTION(GETFOLLOWERS_LIST):
		MALLOC(  t_wb_get_statuses_followers );
		break;

		//------------------------------------私信 
	case WEIBO_OPTION(GETDIRECTMSG):
		MALLOC(  t_wb_get_direct_message );
		break;

	case WEIBO_OPTION(GETDIRESTMSG_SENT):
		MALLOC(  t_wb_get_direct_message_sent );
		break;

	case WEIBO_OPTION(PUTDIRECTMSG_NEW):
		MALLOC(  t_wb_put_direct_message_new  );
		break;

	case WEIBO_OPTION(PUTDIRECTMSG_DESTROY):
		MALLOC(  t_wb_put_direct_message_destroy );
		break;

	case WEIBO_OPTION(GETDIRECTMSG_WITH):
		MALLOC(  t_wb_get_direct_message_with );
		break;

		//------------------------------------关注
	case WEIBO_OPTION(PUTFRIENDSHIPS_CREATE):
		MALLOC( t_wb_put_friendships_create );
		break;

	case WEIBO_OPTION(PUTFRIENDSHIPS_CREATE_BATCH):
		MALLOC( t_wb_put_friendships_create_batch );
		break;

	case WEIBO_OPTION(PUTFRIENDSHIPS_DESTROY):
		MALLOC(  t_wb_put_friendships_destroy );
		break;

	case WEIBO_OPTION(GETFRIENDSHIPS_EXISTS):
		MALLOC( t_wb_get_friendships_show );
		break;

	case WEIBO_OPTION(GETFRIENDSHIPS_BATCH_EXISTS):
		MALLOC( t_wb_get_friendships_batchexist );
		break;

		//------------------------------------Social Graph
	case WEIBO_OPTION(GETFOLLOWER_IDS):
		MALLOC( t_wb_get_followers_ids );
		break;

	case WEIBO_OPTION(GETFRIEND_IDS):
		MALLOC(  t_wb_get_friends_ids );
		break;

		//-----------------------------------账号
	case WEIBO_OPTION(GETACCOUNT_VERIFY):
		MALLOC( t_wb_get_account_verify_credentials ) ;
		break;

	case WEIBO_OPTION(GETACCOUNT_RATELIMIT):
		MALLOC( t_wb_get_account_rate_limit_status );
		break;

	case WEIBO_OPTION(PUTACCOUNT_QUITSESSION):
		MALLOC( t_wb_put_account_end_session ) ;
		break;

	case WEIBO_OPTION(PUTACCOUNT_UPDATE_PROFILEIMAGE):
		MALLOC( t_wb_put_account_up_profileimage  );
		break;

	case WEIBO_OPTION(PUTACCOUNT_UPDATE_PROFILE):
		MALLOC( t_wb_put_account_up_profile  );
		break;

	case WEIBO_OPTION(PUTACCOUNT_REGISTER):
		MALLOC( t_wb_put_account_register  );
		break;

		//----------------------------- 收藏
	case WEIBO_OPTION(GETFAVORITES):
		MALLOC( t_wb_get_favorites  );
		break;

	case WEIBO_OPTION(PUTFAVORITES_CREATE):
		MALLOC( t_wb_put_favorites_create );
		break;

	case WEIBO_OPTION(PUTFAVORITES_DESTROY):
		MALLOC( t_wb_put_favorites_destroy );
		break;

        //------------------------------登录/OAuth

	case WEIBO_OPTION(OAUTH_REQUEST_TOKEN):
		MALLOC( t_wb_oauth_request_token );
		break;

	case WEIBO_OPTION(OAUTH_AUTHORIZE):
		MALLOC( t_wb_authorize);
		break;

	case WEIBO_OPTION(OAUTH_ACCESS_TOKEN):
		MALLOC( t_wb_oauth_access_token );
		break;

	//------------------------------登录/XAuth
	case WEIBO_OPTION(XAUTH_ACCESS_TOKEN):
		MALLOC( t_wb_xauth_access_token );
		break;
		// 表情
	case WEIBO_OPTION(GET_EMOTIONS):
		MALLOC( t_wb_emotions );
		break;

		// 用户搜索 
	case WEIBO_OPTION(GET_USERS_SEARCH):
		MALLOC( t_wb_users_search );
		break;

		// 微博搜索 
	case WEIBO_OPTION(GET_WB_SEARCH):
		MALLOC( t_wb_search );
		break;

	case WEIBO_OPTION(GET_STATUSES_SEARCH):
		MALLOC( t_wb_statuses_search );
		break;

	case WEIBO_OPTION(GET_PROVINCES):
		MALLOC( t_wb_provinces );
		break;

	case WEIBO_OPTION(COOKIE):
		MALLOC( t_wb_cookie );
		break;

	case WEIBO_OPTION(UPDATETGT):
		MALLOC( t_wb_updateTGT );
		break;

	case WEIBO_OPTION(CUSTOM):
		MALLOC(  t_wb_custom );
		break;

	case WEIBO_OPTION(GET_USERS_HOT):
		MALLOC( t_wb_users_hot );
		break;
	case WEIBO_OPTION(POST_USERS_REMARK):
		MALLOC( t_wb_users_remark );
		break;
	case WEIBO_OPTION(GET_USERS_SUGGESTIONS):
		MALLOC( t_wb_users_suggestions );
		break;

	// 话题接口 ,by welbon,2011-01-10
	case WEIBO_OPTION(GET_TRENDS)://trends 获取某人的话题
		MALLOC( t_wb_trends );
		break;
	case WEIBO_OPTION(GET_TRENDS_STATUSES)://trends/statuses 获取某一话题下的微博
		MALLOC( t_wb_trends_statuses );
		break;
	case WEIBO_OPTION(POST_TRENDS_FOLLOW)://trends/follow 关注某一个话题
		MALLOC( t_wb_trends_follow );
		break;
	case WEIBO_OPTION(DELETE_TRENDS_DESTROY)://trends/destroy 取消关注的某一个话题
		MALLOC( t_wb_trends_destroy );
		break;
	case WEIBO_OPTION(GET_TRENDS_HOURLY)://trends/destroy 按小时返回热门话题
		MALLOC( t_wb_trends_hourly );
		break;
	case WEIBO_OPTION(GET_TRENDS_DAYLIY)://trends/daily 按日期返回热门话题。返回某一日期的话题
		MALLOC( t_wb_trends_daily );
		break;
	case WEIBO_OPTION(GET_TRENDS_WEEKLIY)://trends/weekly 按周返回热门话题。返回某一日期之前某一周的话题
		MALLOC( t_wb_trends_weekly );
		break;

	// 黑名单接口 ,by welbon,2011-01-10
	case WEIBO_OPTION(POST_BLOCKS_CREATE)://将某用户加入黑名单
		MALLOC( t_wb_blocks_create );
		break;
	case WEIBO_OPTION(POST_BLOCKS_DESTROY)://将某用户移出黑名单
		MALLOC( t_wb_blocks_destroy );
		break;
	case WEIBO_OPTION(GET_BLOCKS_EXISTS)://检测某用户是否是黑名单用户
		MALLOC( t_wb_blocks_exist );
		break;
	case WEIBO_OPTION(GET_BLOCKS_BLOCKING)://列出黑名单用户(输出用户详细信息)
		MALLOC( t_wb_blocks_blocking );
		break;
	case WEIBO_OPTION(GET_BLOCKS_BLOCKING_IDS)://列出分页黑名单用户（只输出id）
		MALLOC( t_wb_blocks_blocking_ids );
		break;

		//用户标签接口 ,by welbon,2011-01-10
	case WEIBO_OPTION(GET_TAGS)://tags 返回指定用户的标签列表
		MALLOC( t_wb_tags );
		break;
	case WEIBO_OPTION(POST_TAGS_CREATE)://tags/create 添加用户标签
		MALLOC( t_wb_tags_create );
		break;
	case WEIBO_OPTION(GET_TAGS_SUGGESTIONS)://tags/suggestions 返回用户感兴趣的标签
		MALLOC( t_wb_tags_suggestions );
		break;
	case WEIBO_OPTION(POST_TAGS_DESTROY)://tags/destroy 删除标签
		MALLOC( t_wb_tags_destroy );
		break;
	case WEIBO_OPTION(POST_TAGS_DESTROY_BATCH)://tags/destroy_batch 批量删除标签
		MALLOC( t_wb_tags_destroy_batch );
		break;

		//Invite Mail
	case WEIBO_OPTION(POST_INVITE_MAILCONTACT)://邀请邮箱联系人
		MALLOC( t_wb_invite_mailcontect);
		break;
	case WEIBO_OPTION(POST_INVITE_MSNCONTACT)://邀请MSN联系人
		MALLOC( t_wb_invite_msncontect );
		break;
	case WEIBO_OPTION(POST_INVITE_SENDMAILS)://发送邀请邮件
		MALLOC( t_wb_invite_sendmails );
		break;

	case WEIBO_OPTION(GET_MEDIA_SHORTURL_BATCH):
		MALLOC( t_wb_media_shorturl_batch);
		break;

	default:
		return 0;
	}

	if( pnewstruct && size )
	{
		memcpy(pnewstruct , senddata , size );
	}
	return pnewstruct;
}

void Weibo_senddata_free(void* senddata)
{
	if( senddata ) 
	{
		free( senddata );
	}
}

int  Weibo_start_request_asyn(struct t_wb_Request* reqSession)
{
	if( !reqSession )
		return -1;

	if( !reqSession->session_ )
	{
		reqSession->session_ = Weibo_httpsession_create();
		if( !reqSession->session_ )
		{
			return -1;
		}
	}
	reqSession->session_->bAsyn_ = true;
	return Weibo_session_start( reqSession->session_ , reqSession);
}

int  Weibo_start_request(struct t_wb_Request* reqSession)
{
	if( !reqSession )
		return ERR_reqSessionParam_nil;

	if( !reqSession->session_ )
	{
		reqSession->session_ = Weibo_httpsession_create();
		if( !reqSession->session_ )
		{
			return ERR_createhttpSession_nil;
		}
	}
	reqSession->session_->bAsyn_ = false;
	return Weibo_session_start( reqSession->session_ , reqSession);
}

int Weibo_stop_request(struct t_wb_Request* reqSession)
{
	if( !reqSession )
		return ERR_reqSessionParam_nil;

	if( !reqSession->session_ )
	{
		return ERR_OK;
	}
	return Weibo_session_stop( reqSession->session_);
}

void Weibo_wait_request(struct t_wb_Request* reqSession)
{
	if( !reqSession )
		return ;

	if( !reqSession->session_ )
	{
		return ;
	}
	return Weibo_session_wait( reqSession->session_ );
}