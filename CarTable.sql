USE [PSBData]
GO
/****** Object:  Table [HumanResource].[CarInsure]    Script Date: 2016/11/27 星期日 00:59:01 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [HumanResource].[CarInsure](
	[ID] [int] NOT NULL,
	[CarID] [nvarchar](10) NOT NULL,
	[Type] [nvarchar](20) NOT NULL,
	[Price] [float] NOT NULL,
	[InsureCompany] [nvarchar](20) NOT NULL,
	[DateofStart] [date] NOT NULL,
	[DateofEnd] [date] NOT NULL,
	[InCharge] [nvarchar](20) NOT NULL,
	[Remark] [text] NULL,
 CONSTRAINT [PK_CarInsure] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [Group1]
) ON [Group1] TEXTIMAGE_ON [Group1]

GO
/****** Object:  Table [HumanResource].[CarMaintain]    Script Date: 2016/11/27 星期日 00:59:01 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [HumanResource].[CarMaintain](
	[ID] [int] NOT NULL,
	[CarID] [nvarchar](10) NOT NULL,
	[Type] [nvarchar](50) NOT NULL,
	[Station] [nvarchar](50) NOT NULL,
	[Price] [float] NOT NULL,
	[Date] [date] NOT NULL,
	[Distance] [int] NOT NULL,
	[InCharge] [nvarchar](20) NOT NULL,
	[Remark] [text] NULL,
 CONSTRAINT [PK_CarMaintain] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [Group1]
) ON [Group1] TEXTIMAGE_ON [Group1]

GO
